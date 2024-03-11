#include "Sparky.h"

#include "Player.h"

ASparky::ASparky()
{

}

ASparky::~ASparky()
{

}

void ASparky::BeginPlay()
{
	AMonster::BeginPlay();

	{
		Renderer = CreateImageRenderer(KirbyRenderOrder::Monster);
		Renderer->SetImage("NormalEnemy_Left.png");
		Renderer->SetTransform({ {0,0}, {256, 256} });

		Renderer->CreateAnimation("Run_Left", "NormalEnemy_Left.png", 0, 1, 0.15f, true);
		Renderer->CreateAnimation("Run_Right", "NormalEnemy_Right.png", 0, 1, 0.15f, true);
	}
	{
		BodyCollision = CreateCollision(KirbyCollisionOrder::Monster);
		BodyCollision->SetColType(ECollisionType::Rect);
		BodyCollision->SetTransform({ {0, -25}, {50, 50} });
	}

	SetAbility(EAbiltyType::Spark);
	SetMoveMaxSpeed(100.0f);

	StateChange(EMonsterState::Move);
}

void ASparky::Tick(float _DeltaTime)
{
	AMonster::Tick(_DeltaTime);
}

void ASparky::MoveStart()
{
	AMonster::MoveStart();

	Renderer->ChangeAnimation(GetAnimationName("Run"));
	DirCheck();
}

void ASparky::Move(float _DeltaTime)
{
	AMonster::Move(_DeltaTime);

	if (AbsorbCheck() == true)
	{
		StateChange(EMonsterState::Absorb);
		return;
	}

	if (IsWallCheck() == true)
	{
		MoveVector = FVector::Zero;
	}

	DirCheck();

	if (DirState == EActorDir::Left)
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}
	else if (DirState == EActorDir::Right)
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	FVector Ground = { GetActorLocation().iX(), GetActorLocation().iY() + 5 };

	if (IsGroundCheck(Ground) == false)
	{
		MoveUpdate(_DeltaTime, true, false, false);
	}
	else
	{
		MoveUpdate(_DeltaTime, true, true, true);
	}
}