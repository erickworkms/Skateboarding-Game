// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CreateDefaultCharacterSettings();
	CreateDefaultCameraSettings();
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	DefineDefaultValues();

	GetWorldTimerManager().SetTimer(
	GeneralTimer,
	this,
	&ABaseCharacter::CharacterTimer,
	0.01, true);
}



























