#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ActiveAction_Pressed()
{
	if (!ButtonIsPressed && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		ButtonIsPressed = true;
		if (CharacterActions == NoAction && CharacterStates == OntheGround)
		{
			BaseVariables.IsUsingSkateboard = false;
		}
		else
		{
			BaseVariables.IsUsingSkateboard = true;
		}
		
	}
}

void ABaseCharacter::ActiveAction_Released()
{
	ButtonIsPressed = false;
}
