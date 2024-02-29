#pragma once
#include <EngineCore\Level.h>

class AFadeOut;

class ULevel112 : public ULevel
{
public:
	ULevel112();
	~ULevel112();

	ULevel112(const ULevel112& _Other) = delete;
	ULevel112(ULevel112&& _Other) noexcept = delete;
	ULevel112& operator=(const ULevel112& _Other) = delete;
	ULevel112& operator=(ULevel112&& _Other) noexcept = delete;

protected:
	AFadeOut* Fade;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

private:

};