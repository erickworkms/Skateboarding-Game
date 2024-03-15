#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ResetDefaultValues()
{
	BaseVariables.ActionIsActived = false;
	
	ButtonIsPressed = false;
	
	CharacterActions = NoAction;
}
