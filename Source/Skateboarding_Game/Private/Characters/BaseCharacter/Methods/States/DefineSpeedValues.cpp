#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABaseCharacter::DefineSpeedValues()
{
	if (SpeedIndex == 0)
	{
		BaseVariables.MaxSpeed = 300;
	}
	else if (SpeedIndex == 1)
	{
		BaseVariables.MaxSpeed = 1000;
	}
	else if (SpeedIndex == 2)
	{
		BaseVariables.MaxSpeed = 2000;
	}

	if (IncreaseSpeed)
	{
		BaseVariables.MaxSpeed += BaseVariables.MaxSpeed * ((IncreaseSpeedValue - DecreaseSpeedValue) * 100);
	}
	else if (DecreaseSpeed)
	{
		BaseVariables.MaxSpeed -= BaseVariables.MaxSpeed * ((DecreaseSpeedValue - IncreaseSpeedValue) * 100);
	}
	
	GetCharacterMovement()->MaxWalkSpeed = BaseVariables.MaxSpeed;
	BaseVariables.IsCharacterMoving = (GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y) > 0;
	BaseVariables.Speed = GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y;
	BaseVariables.Speed = FMath::FInterpTo(BaseVariables.Speed,
								  GetCapsuleComponent()->GetComponentVelocity().Size(), 0.01f, 0.01f);
}
