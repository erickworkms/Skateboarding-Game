#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter/BaseCharacter.h"
#include "GameFramework/PlayerController.h"
#include "GameSettings/HUDs/SkateboardHUD.h"
#include "SkateboardController.generated.h"

/**
 * 
 */
UCLASS()
class SKATEBOARDING_GAME_API ASkateboardController : public APlayerController
{
	GENERATED_BODY()
public:
		
	UPROPERTY(BlueprintReadWrite)
	ABaseCharacter* CharacterControlled;

	UPROPERTY(BlueprintReadWrite)
	ASkateboardHUD* Hud;

protected:
	virtual void BeginPlay() override;
};
