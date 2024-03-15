// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckActionsVariables.h"
#include "Characters/BaseCharacter/BaseCharacter.h"

void UCheckActionsVariables::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float Total)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
	
	if(IsValid(Character))
	{
		Character->ReceivePointsContinue = true;
	}
}

void UCheckActionsVariables::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameSec)
{
	
}

void UCheckActionsVariables::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
	
	if(IsValid(Character))
	{
		Character->CharacterActions = NoAction;
		Character->ReceivePointsContinue = false;
	}
}
