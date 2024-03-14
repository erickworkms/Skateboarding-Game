#pragma once
#include "GameFramework/GameModeBase.h"
#include "GameSettings/HUDs/SkateboardHUD.h"
#include "SkateboardGameMode.generated.h"

UCLASS()
class SKATEBOARDING_GAME_API ASkateboardGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ASkateboardGameMode();
public:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	ASkateboardHUD* Hud;
};