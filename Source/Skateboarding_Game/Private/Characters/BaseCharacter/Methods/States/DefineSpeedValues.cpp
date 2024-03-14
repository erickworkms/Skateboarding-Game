#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABaseCharacter::DefineSpeedValues()
{
	GetCharacterMovement()->MaxWalkSpeed = BaseVariables.MaxSpeed;
	BaseVariables.IsCharacterMoving = (GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y) > 0;
	BaseVariables.Speed = GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y;
	BaseVariables.Speed = FMath::FInterpTo(BaseVariables.Speed,
								  GetCapsuleComponent()->GetComponentVelocity().Size(), 0.01f, 0.01f);
}
