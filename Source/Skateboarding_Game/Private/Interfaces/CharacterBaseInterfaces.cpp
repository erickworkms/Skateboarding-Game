#include "CharacterBaseInterfaces.h"

void ICharacterBaseInterfaces::DefineDefaultValues()
{
}

void ICharacterBaseInterfaces::ResetDefaultValues()
{
}

void ICharacterBaseInterfaces::DefineSpeedValues()
{
}

void ICharacterBaseInterfaces::DefineCharacterState()
{
}

void ICharacterBaseInterfaces::CharacterTimer()
{
}

FBaseStructs ICharacterBaseInterfaces::ReturnCharacterInfo()
{
	return FBaseStructs();
}

EBaseCharacterStates ICharacterBaseInterfaces::ReturnCharacterStates()
{
	return OntheGround;
}

EBaseActionEnums ICharacterBaseInterfaces::ReturnCharacterActions()
{
	return NoAction;
}
