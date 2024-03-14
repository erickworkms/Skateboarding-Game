#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABaseCharacter::DefineSpeedValues()
{
	if (BaseVariables.IsUsingSkateboard)
	{
		switch (SpeedIndex)
		{
		case 0:
			BaseVariables.MaxSpeed = 300;
			break;
		case 1:
			BaseVariables.MaxSpeed = 1000;
			break;
		case 2:
			BaseVariables.MaxSpeed = 2000;
			break;
		default:
			BaseVariables.MaxSpeed = 300;
			break;
		}
	}
	else if (!BaseVariables.IsUsingSkateboard)
	{
		if (RunActived)
		{
			BaseVariables.MaxSpeed = 700;
		}
		else
		{
			BaseVariables.MaxSpeed = 300;
		}
	}


	
	if (IncreaseSpeedValue > 0)
	{
		IncreaseSpeedValue -= 0.01f;
	}
	else
	{
		SpeedIndex = 0;
		IncreaseSpeedValue = 0;
	}
	if (DecreaseSpeedValue > 0)
	{
		DecreaseSpeedValue -= 0.005f;
	}
	else
	{
		SpeedIndex = 0;
		DecreaseSpeedValue = 0;
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow,FString::SanitizeFloat(IncreaseSpeedValue));
	// if (SpeedIndex == 0)
	//  {
	//  	
	//  }
	//  else if (SpeedIndex == 1)
	//  {
	//  	BaseVariables.MaxSpeed = 1000;
	//  }
	//  else if (SpeedIndex == 2)
	//  {
	//  	
	//  }
	//BaseVariables.MaxSpeed = 300;
	// if (IncreaseSpeed)
	// {
	// 	BaseVariables.MaxSpeed += BaseVariables.MaxSpeed * ((IncreaseSpeedValue - DecreaseSpeedValue) * 100);
	// }
	// else if (DecreaseSpeed)
	// {
	// 	BaseVariables.MaxSpeed -= BaseVariables.MaxSpeed * ((DecreaseSpeedValue - IncreaseSpeedValue) * 100);
	// }

	if ((RunActived && BaseVariables.Speed <= 0) || BaseVariables.IsUsingSkateboard)
	{
		RunActived = false;
	}

	GetCharacterMovement()->MaxWalkSpeed = BaseVariables.MaxSpeed;
	BaseVariables.IsCharacterMoving = (GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y) > 0;
	BaseVariables.Speed = FMath::FInterpTo(BaseVariables.Speed,
	                                       GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
	                                       + GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y, 0.01f, 10.f);
}
