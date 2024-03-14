// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CheckActionsVariables.generated.h"

/**
 * 
 */
UCLASS()
class SKATEBOARDING_GAME_API UCheckActionsVariables : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation, float Total) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation, float FrameSec) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation) override;
};


