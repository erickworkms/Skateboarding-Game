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

void ICharacterBaseInterfaces::CreateDefaultCharacterSettings()
{
}

void ICharacterBaseInterfaces::CreateDefaultCameraSettings()
{
}

void ICharacterBaseInterfaces::CharacterTimer()
{
}

FBaseStructs ICharacterBaseInterfaces::ReturnCharacterInfo()
{
	return FBaseStructs();
}

FBaseCharacterStates ICharacterBaseInterfaces::ReturnCharacterStates()
{
	return OntheGround;
}

FBaseActionEnums ICharacterBaseInterfaces::ReturnCharacterActions()
{
	return NoAction;
}
