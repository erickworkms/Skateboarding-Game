// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Structures/BaseEnums.h"
#include "ActionCollision.generated.h"

UCLASS()
class SKATEBOARDING_GAME_API AActionCollision : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActionCollision();

	UPROPERTY()
	UBoxComponent* Collision;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EBasePermittedActionEnums> PossibleAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void EnterCollision(UPrimitiveComponent* OverlappedComp, AActor* CharacterDetected,
								   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

	UFUNCTION()
	void EndCollision(UPrimitiveComponent* OverlappedComp, AActor* CharacterDetected,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
