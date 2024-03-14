#pragma once
#include "GameFramework/HUD.h"
#include "SkateboardHUD.generated.h"

UCLASS()
class SKATEBOARDING_GAME_API ASkateboardHUD : public AHUD
{
	GENERATED_BODY()

	ASkateboardHUD();
public:
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void PauseGame();

	UFUNCTION(BlueprintImplementableEvent)
	void UnPauseGame();

	UFUNCTION(BlueprintImplementableEvent)
	void ExitGame();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowControllerMap();

	UFUNCTION(BlueprintImplementableEvent)
	void ChooseOptionHud();
	
	UFUNCTION(BlueprintImplementableEvent)
	void IncreaseButtonValue();

	UFUNCTION(BlueprintImplementableEvent)
	void DecreaseButtonValue();
};