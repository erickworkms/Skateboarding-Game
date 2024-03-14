#include "Characters/BaseCharacter/BaseCharacter.h"
#include "GameSettings/Controller/SkateboardController.h"
#include "GameSettings/GameMode/SkateboardGameMode.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::PauseGame_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
	
		if (UGameplayStatics::IsGamePaused(GetWorld()))
		{
			if (SkateGameMode)
			{
				SkateGameMode->Hud->UnPauseGame();
			}
		}
		else if (!UGameplayStatics::IsGamePaused(GetWorld()))
		{
			if (SkateGameMode)
			{
				SkateGameMode->Hud->PauseGame();
			}
		}
	}
}

void ABaseCharacter::PauseGame_Released()
{
	ButtonIsPressed = false;
}
