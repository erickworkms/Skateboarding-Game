// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::MoveForward(float valor)
{
}

void ABaseCharacter::MoveSide(float valor)
{
}

void ABaseCharacter::ForwardCameraAngle(float valor)
{
}

void ABaseCharacter::SideCameraAngle(float valor)
{
}

void ABaseCharacter::ActiveJump_Pressed()
{
}

void ABaseCharacter::ActiveJump_Released()
{
}

void ABaseCharacter::ActiveAction_Pressed()
{
}

void ABaseCharacter::ActiveAction_Released()
{
}

void ABaseCharacter::ChangeSkateboardUse_Pressed()
{
}

void ABaseCharacter::ChangeSkateboardUse_Released()
{
}

void ABaseCharacter::SpeedUP_Pressed()
{
}

void ABaseCharacter::SpeedUP_Released()
{
}

void ABaseCharacter::CheckLife()
{
	ICharacterBaseInterfaces::CheckLife();
}

void ABaseCharacter::DefineDefaultValues()
{
	ICharacterBaseInterfaces::DefineDefaultValues();
}

void ABaseCharacter::ResetDefaultValues()
{
	ICharacterBaseInterfaces::ResetDefaultValues();
}

void ABaseCharacter::DefineSpeedValues()
{
	ICharacterBaseInterfaces::DefineSpeedValues();
}

void ABaseCharacter::CreateDefaultCharacterSettings()
{
	ICharacterBaseInterfaces::CreateDefaultCharacterSettings();
}

void ABaseCharacter::CharacterTimer()
{
	ICharacterBaseInterfaces::CharacterTimer();
}

FBaseStructs ABaseCharacter::ReturnCharacterInfo()
{
	return ICharacterBaseInterfaces::ReturnCharacterInfo();
}

FBaseCharacterStates ABaseCharacter::ReturnCharacterStates()
{
	return ICharacterBaseInterfaces::ReturnCharacterStates();
}

FBaseActionEnums ABaseCharacter::ReturnCharacterActions()
{
	return ICharacterBaseInterfaces::ReturnCharacterActions();
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &ABaseCharacter::MoveSide);
	
	PlayerInputComponent->BindAxis(TEXT("ForwardCameraAngle"), this, &ABaseCharacter::ForwardCameraAngle);
	PlayerInputComponent->BindAxis(TEXT("SideCameraAngle"), this, &ABaseCharacter::SideCameraAngle);
	
	PlayerInputComponent->BindAction(TEXT("ActiveJump"), IE_Pressed, this, &ABaseCharacter::ActiveJump_Pressed);
	PlayerInputComponent->BindAction(TEXT("ActiveJump"), IE_Released, this, &ABaseCharacter::ActiveJump_Released);
	
	PlayerInputComponent->BindAction(TEXT("ActiveAction"), IE_Pressed, this,
									 &ABaseCharacter::ActiveAction_Pressed);
	PlayerInputComponent->BindAction(TEXT("ActiveAction"), IE_Released, this,
									 &ABaseCharacter::ActiveAction_Released);
	
	PlayerInputComponent->BindAction(TEXT("ChangeSkateboardUse"), IE_Pressed, this,
									 &ABaseCharacter::ChangeSkateboardUse_Pressed);
	PlayerInputComponent->BindAction(TEXT("ChangeSkateboardUse"), IE_Released, this,
									 &ABaseCharacter::ChangeSkateboardUse_Released);
	
	PlayerInputComponent->BindAction(TEXT("SpeedUP"), IE_Pressed, this, &ABaseCharacter::SpeedUP_Pressed);
	PlayerInputComponent->BindAction(TEXT("SpeedUP"), IE_Released, this, &ABaseCharacter::SpeedUP_Pressed);

}

