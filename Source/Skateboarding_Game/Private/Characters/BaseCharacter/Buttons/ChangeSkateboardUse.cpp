#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ChangeSkateboardUse_Pressed()
{
	if (!ButtonIsPressed && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		ButtonIsPressed = true;
		if (BaseVariables.IsUsingSkateboard)
		{
			BaseVariables.IsUsingSkateboard = false;
		}
		else
		{
			BaseVariables.IsUsingSkateboard = true;
			RunActived = false;
		}
	}
}

void ABaseCharacter::ChangeSkateboardUse_Released()
{
	ButtonIsPressed = false;
}
