#pragma once

#include "CoreMinimal.h"

class SKATEBOARDING_GAME_API FBaseEnum
{
public:
	FBaseEnum();
};

UENUM(BlueprintType)
enum EBaseActionEnums
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
enum EBasePermittedActionEnums
{
	NormalJumpingPermitted UMETA(DisplayName = "Normal Jumping Permitted"),
	SkateJumpingPermitted UMETA(DisplayName = "Skate Jumping Permitted"),
	WallSliddingPermitted UMETA(DisplayName = "Wall Slidding Permitted"),
	LadderSliddingPermitted UMETA(DisplayName = "Ladder Slidding Permitted"),
	WallRollPermitted UMETA(DisplayName = "Wall Roll Permitted"),
	BackJumpPermitted UMETA(DisplayName = "Back Jump Permitted"),
	AirFeintPermitted UMETA(DisplayName = "Air Feint Permitted"),
	GroundFeintPermitted UMETA(DisplayName = "Ground Feint Permitted"),
	NoActionPermitted UMETA(DisplayName = "No Action Permitted")
};

UENUM(BlueprintType)
enum EBaseCharacterStates
{
	OntheGround UMETA(DisplayName = "OntheGround"),
	FallingIntheAir UMETA(DisplayName = "Falling"),
	FlyingIntheAir UMETA(DisplayName = "Flying")
};
