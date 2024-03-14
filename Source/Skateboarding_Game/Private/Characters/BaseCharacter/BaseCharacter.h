// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Skateboarding_Game/Private/Interfaces/CharacterBaseInterfaces.h"
#include "Skateboarding_Game/Private/Structures/BaseEnums.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ABaseCharacter : public ACharacter, public ICharacterBaseInterfaces
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

    //Basic Character Components 
	UPROPERTY()
	USpringArmComponent* SpringArm;
	UPROPERTY()
	UCameraComponent* CharacterCamera;
	UPROPERTY()
	USkeletalMeshComponent* SkateboardMesh;
	
	//Basic Variables
	
	TEnumAsByte<FBaseCharacterStates> CharacterStates;
	
	TEnumAsByte<FBaseActionEnums> CharacterActions;

	UPROPERTY()
	FBaseStructs BaseVariables;
	
	UPROPERTY()
	FTimerHandle GeneralTimer;
	UPROPERTY()
	FTimerHandle ActionTimer;
	UPROPERTY()
	FTimerHandle ButtonPressTimer;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float valor);
	void MoveSide(float valor);
	void ForwardCameraAngle(float valor);
	void SideCameraAngle(float valor);
	
	void ActiveJump_Pressed();
	void ActiveJump_Released();
	
	void ActiveAction_Pressed();
	void ActiveAction_Released();
	
	void ChangeSkateboardUse_Pressed();
	void ChangeSkateboardUse_Released();

	void SpeedUP_Pressed();
	void SpeedUP_Released();
	
	virtual void DefineDefaultValues() override;
	virtual void ResetDefaultValues() override;
	virtual void DefineSpeedValues() override;
	void CreateDefaultCharacterSettings();
	virtual void CharacterTimer() override;
	void CreateDefaultCameraSettings();

	virtual void DefineCharacterState() override;
	
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual FBaseStructs ReturnCharacterInfo() override;
	virtual FBaseCharacterStates ReturnCharacterStates() override;
	virtual FBaseActionEnums ReturnCharacterActions() override;
};
