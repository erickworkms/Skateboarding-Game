#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ActiveJump_Pressed()
{
	if (!ButtonIsPressed && CharacterStates == OntheGround && CharacterActions != NormalJumping && CharacterActions != SkateJumping)
	{
		if (BaseVariables.IsUsingSkateboard)
		{
			CharacterActions = SkateJumping;
		}
		else if (!BaseVariables.IsUsingSkateboard)
		{
			CharacterActions = NormalJumping;
		}
		Jump();
		ButtonIsPressed = true;
	}
}

void ABaseCharacter::ActiveJump_Released()
{
	ButtonIsPressed = false;
}