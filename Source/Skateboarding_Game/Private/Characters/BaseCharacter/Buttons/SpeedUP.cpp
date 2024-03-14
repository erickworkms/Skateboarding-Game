
#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::SpeedUP_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
		IncreaseSpeed = true;
		IncreaseSpeedValue += 0.2;

		if (!RunActived && BaseVariables.IsUsingSkateboard)
		{
			if (DecreaseSpeedValue > 0)
			{
				DecreaseSpeedValue -= IncreaseSpeedValue;
			}
			else
			{
				DecreaseSpeedValue = 0;
			}
		
			if (IncreaseSpeedValue > 1 && IncreaseSpeedValue < 2)
			{
				SpeedIndex = 1;
			}
			else if (IncreaseSpeedValue > 2)
			{
				SpeedIndex = 2;
			}
			else
			{
				SpeedIndex = 0;
			}
		}
		else if(!RunActived && IncreaseSpeedValue > 0.3)
		{
			RunActived = true;
		}
		
	}
}

void ABaseCharacter::SpeedUP_Released()
{
	ButtonIsPressed = false;
}