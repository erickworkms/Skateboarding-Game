#pragma once

#include "Skateboarding_Game/Private/Structures/BaseEnums.h"
#include "Skateboarding_Game/Private/Structures/BaseStructs.h"
#include "CharacterBaseInterfaces.generated.h"

UINTERFACE(MinimalAPI)
class UCharacterBaseInterfaces : public UInterface
{
public:
	GENERATED_BODY()
};
class SKATEBOARDING_GAME_API ICharacterBaseInterfaces
{
	GENERATED_BODY()

public:
	virtual void CheckLife();
	virtual void DefineDefaultValues();
	virtual void ResetDefaultValues();
	virtual void DefineSpeedValues();
	
	virtual void CreateDefaultCharacterSettings();
	virtual void CharacterTimer();
	
	virtual FBaseStructs ReturnCharacterInfo();
	virtual FBaseCharacterStates ReturnCharacterStates();
	virtual FBaseActionEnums ReturnCharacterActions();
};