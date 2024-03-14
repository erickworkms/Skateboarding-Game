#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::MoveForward(float valor)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding && CharacterActions != BackJump)
	{
		FVector Forward = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Forward, valor);
	}
}

void ABaseCharacter::MoveSide(float valor)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding && CharacterActions != BackJump)
	{
		FVector Side = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Side, valor);
	}
}