#pragma once
#include <EngineCore\Actor.h>

class APlayer : public AActor
{
public:
	APlayer();
	~APlayer();

	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	float Gravity = 500.0f;

	float AnimationTime = 0.0f;
	int AnimationFrame = 0;
	UImageRenderer* Renderer;
};