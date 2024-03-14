
#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::SpeedDown_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;
		DecreaseSpeed = true;
		DecreaseSpeedValue += 0.2;

		if (IncreaseSpeedValue > 0)
		{
			IncreaseSpeedValue -= DecreaseSpeedValue;
		}
		else
		{
			DecreaseSpeedValue = 0;
		}
		
		if (DecreaseSpeedValue > 1 && DecreaseSpeedValue < 2)
		{
			SpeedIndex = 1;
		}
		else if (DecreaseSpeedValue > 2)
		{
			SpeedIndex = 2;
		}
		else
		{
			SpeedIndex = 0;
		}
	}
}

void ABaseCharacter::SpeedDown_Released()
{
	ButtonIsPressed = false;
}


