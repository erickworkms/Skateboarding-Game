
#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::SpeedDown_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
		if (!RunActived && BaseVariables.IsUsingSkateboard)
		{
			DecreaseSpeed = true;
		}
	}
}

void ABaseCharacter::SpeedDown_Released()
{
	ButtonIsPressed = false;
	DecreaseSpeed = false;
}


