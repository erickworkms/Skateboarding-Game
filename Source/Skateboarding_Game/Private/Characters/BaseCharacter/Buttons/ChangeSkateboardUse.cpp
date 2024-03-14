#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ChangeSkateboardUse_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
		if (BaseVariables.IsUsingSkateboard)
		{
			BaseVariables.IsUsingSkateboard = false;
		}
		else
		{
			BaseVariables.IsUsingSkateboard = true;
		}
		
	}
}

void ABaseCharacter::ChangeSkateboardUse_Released()
{
	ButtonIsPressed = false;
}
