#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ResetDefaultValues()
{
	BaseVariables.ActionIsActived = false;
	//BaseVariables.IsCharacterMoving = false;
	BaseVariables.IsUsingSkateboard = false;
	
	ButtonIsPressed = false;
	
	//CharacterStates = OntheGround;
	CharacterActions = NoAction;
}
