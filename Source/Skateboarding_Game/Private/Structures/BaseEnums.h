#pragma once

#include "CoreMinimal.h"

class SKATEBOARDING_GAME_API FBaseEnum
{
public:
	FBaseEnum();
};

UENUM(BlueprintType)
enum FBaseActionEnums
{
	NormalJumping UMETA(DisplayName = "Normal Jumping"),
	SkateJumping UMETA(DisplayName = "Skate Jumping"),
	WallSlidding UMETA(DisplayName = "Wall Slidding"),
	LadderSlidding UMETA(DisplayName = "Ladder Slidding"),
	WallRoll UMETA(DisplayName = "Wall Roll"),
	BackJump UMETA(DisplayName = "Back Jump"),
	ArFeint UMETA(DisplayName = "Ar Feint"),
	GroundFeint UMETA(DisplayName = "Ground Feint"),
	NoAction UMETA(DisplayName = "No Action")
};

UENUM(BlueprintType)
enum FBaseCharacterStates
{
	OntheGround UMETA(DisplayName = "OntheGround"),
	Falling UMETA(DisplayName = "Falling"),
	Flying UMETA(DisplayName = "Flying")
};
