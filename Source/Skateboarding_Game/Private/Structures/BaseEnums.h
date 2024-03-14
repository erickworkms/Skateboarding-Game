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
	AirFeint UMETA(DisplayName = "Air Feint"),
	GroundFeint UMETA(DisplayName = "Ground Feint"),
	NoAction UMETA(DisplayName = "No Action")
};

UENUM(BlueprintType)
enum FBaseCharacterStates
{
	OntheGround UMETA(DisplayName = "OntheGround"),
	FallingIntheAir UMETA(DisplayName = "Falling"),
	FlyingIntheAir UMETA(DisplayName = "Flying")
};
