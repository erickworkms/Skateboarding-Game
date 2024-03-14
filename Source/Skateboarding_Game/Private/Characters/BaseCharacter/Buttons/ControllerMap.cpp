
#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ControllerMap_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
	
		if (UGameplayStatics::IsGamePaused(GetWorld()))
		{
			if (SkateGameMode)
			{
				SkateGameMode->Hud->ShowControllerMap();
			}
		}
	}
}

void ABaseCharacter::ControllerMap_Released()
{
	ButtonIsPressed = false;
}


