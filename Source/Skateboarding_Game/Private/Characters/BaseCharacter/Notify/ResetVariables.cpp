// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter/Notify/ResetVariables.h"

#include "Characters/BaseCharacter/BaseCharacter.h"

void UResetVariables::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
	
	if(IsValid(Character))
	{
		Character->ResetDefaultValues();
	}
}
