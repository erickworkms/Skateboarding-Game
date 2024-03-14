// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structures/BaseEnums.h"
#include "Structures/BaseStructs.h"
#include "BaseCharacterAnimBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class UBaseCharacterAnimBlueprint : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float Speed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float AnimationSpeed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float CharacterAngle = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float MaxSpeed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool ActionIsActived = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool IsCharacterMoving = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool IsUsingSkateboard = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TEnumAsByte<EBaseCharacterStates> CharacterStates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TEnumAsByte<EBaseActionEnums> CharacterActions;

private:
	UBaseCharacterAnimBlueprint();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds);
	
	UPROPERTY()
	APawn* Character;
};
