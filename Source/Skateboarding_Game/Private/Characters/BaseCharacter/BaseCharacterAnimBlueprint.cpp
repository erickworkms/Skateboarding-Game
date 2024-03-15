// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter/BaseCharacterAnimBlueprint.h"

#include "BaseCharacter.h"

UBaseCharacterAnimBlueprint::UBaseCharacterAnimBlueprint()
{
	Direction = 0;
	Speed = 0;
	AnimationSpeed = 1;
	CharacterAngle = 0;
	MaxSpeed = 0;
	ActionIsActived = false;
	IsCharacterMoving = false;
	IsUsingSkateboard = false;

	CharacterStates = OntheGround;
	CharacterActions = NoAction;

	Character = nullptr;
}

void UBaseCharacterAnimBlueprint::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = TryGetPawnOwner();
}

void UBaseCharacterAnimBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!Character)
	{
		return;
	}
	if (Character->IsA(ABaseCharacter::StaticClass()))
	{
		ABaseCharacter* CharacterReference = Cast<ABaseCharacter>(Character);
		
		if (CharacterReference)
		{
			Direction = CharacterReference->BaseVariables.Direction;
			Speed = CharacterReference->BaseVariables.Speed;
			AnimationSpeed = CharacterReference->BaseVariables.AnimationSpeed;
			CharacterAngle = CharacterReference->BaseVariables.CharacterAngle;
			MaxSpeed = CharacterReference->BaseVariables.MaxSpeed;
			ActionIsActived = CharacterReference->BaseVariables.ActionIsActived;
			IsCharacterMoving = CharacterReference->BaseVariables.IsCharacterMoving;
			IsUsingSkateboard = CharacterReference->BaseVariables.IsUsingSkateboard;
			IncreaseSpeed = CharacterReference->IncreaseSpeed;
			DecreaseSpeed = CharacterReference->DecreaseSpeed;

			CharacterStates = CharacterReference->CharacterStates;
			CharacterActions = CharacterReference->CharacterActions;
		}
	}
}
