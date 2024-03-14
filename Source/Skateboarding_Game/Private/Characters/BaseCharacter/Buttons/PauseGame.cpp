
#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::PauseGame_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;

		if (UGameplayStatics::IsGamePaused(GetWorld()))
		{
			UGameplayStatics::SetGamePaused(GetWorld(),false);
		}
		else
		{
			UGameplayStatics::SetGamePaused(GetWorld(),true);
		}

	}
}

void ABaseCharacter::PauseGame_Released()
{
	ButtonIsPressed = false;
}