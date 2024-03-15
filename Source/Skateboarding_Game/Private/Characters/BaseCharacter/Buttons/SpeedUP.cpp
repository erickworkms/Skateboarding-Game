#include "Characters/BaseCharacter/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void ABaseCharacter::SpeedUP_Pressed()
{
	if (!ButtonIsPressed)
	{
		ButtonIsPressed = true;

		if (!RunActived && BaseVariables.IsUsingSkateboard)
		{
			IncreaseSpeed = true;
		}
		else if (!RunActived)
		{
			RunActived = true;
		}
	}
}

void ABaseCharacter::SpeedUP_Released()
{
	ButtonIsPressed = false;
	IncreaseSpeed = false;
	
	if (BaseVariables.IsUsingSkateboard)
	{
		RunActived = false;
	}
}

void ABaseCharacter::LastVelocityTimer()
{
	GetCharacterMovement()->AddImpulse((GetActorForwardVector() * 10000.0f)/ 500, true);
}

