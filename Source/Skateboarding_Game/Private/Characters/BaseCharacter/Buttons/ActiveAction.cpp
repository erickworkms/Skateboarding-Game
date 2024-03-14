#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ActiveAction_Pressed()
{
	if (!ButtonIsPressed)
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
