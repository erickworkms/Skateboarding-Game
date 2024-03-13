#pragma once

#include "BaseStructs.generated.h"

USTRUCT(BlueprintType)
struct FBaseStructs
{
	GENERATED_BODY()

	FBaseStructs(float Speed, float CharacterAngle, float Direction, float AnimationSpeed, float MaxSpeed,
		bool bIsCharacterMoving, bool bIsUsingSkateboard, bool bActionIsActived)
		: Speed(Speed),
		  CharacterAngle(CharacterAngle),
		  Direction(Direction),
		  AnimationSpeed(AnimationSpeed),
		  MaxSpeed(MaxSpeed),
		  IsCharacterMoving(bIsCharacterMoving),
		  IsUsingSkateboard(bIsUsingSkateboard),
		  ActionIsActived(bActionIsActived)
	{
	}
	FBaseStructs()
			: Speed(0),
			  CharacterAngle(0),
			  Direction(0),
			  AnimationSpeed(0),
			  MaxSpeed(0),
			  IsCharacterMoving(false),
			  IsUsingSkateboard(false),
			  ActionIsActived(false)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CharacterAngle; // Used to compare the character angle with objects in the scene
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Direction; //Used to check a target direction in the scene
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AnimationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCharacterMoving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsUsingSkateboard; //Check if a character is walking with and without the skateboard
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ActionIsActived;  // Check if a character is playing any action movements 

};
