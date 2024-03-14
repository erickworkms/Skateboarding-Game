#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::MoveForward(float Value)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding && CharacterActions != BackJump)
	{
		FVector Forward = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Forward, Value);
	}
}

void ABaseCharacter::MoveSide(float Value)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding && CharacterActions != BackJump)
	{
		FVector Side = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Side, Value);
	}
}