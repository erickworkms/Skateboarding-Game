#include "Characters/BaseCharacter/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABaseCharacter::DefineCharacterState()
{
	if (GetCharacterMovement()->MovementMode == MOVE_Falling)
	{
		CharacterStates = FallingIntheAir;
	}
	else if (GetCharacterMovement()->MovementMode == MOVE_Flying)
	{
		CharacterStates = FlyingIntheAir;
	}
	else if (GetCharacterMovement()->MovementMode == MOVE_Walking)
	{
		CharacterStates = OntheGround;
	}
	else
	{
		CharacterStates = OntheGround;
	}
}
