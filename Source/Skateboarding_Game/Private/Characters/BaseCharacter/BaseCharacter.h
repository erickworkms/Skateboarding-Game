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
	bool IncreaseSpeed = false;
	bool DecreaseSpeed = true;
	bool ButtonIsPressed = false;
	float IncreaseSpeedValue = 0;
	float DecreaseSpeedValue = 0;
	float PressedButtonValue = 0;
	int SpeedIndex = 0;
	
	
	TEnumAsByte<EBaseCharacterStates> CharacterStates;
	
	TEnumAsByte<EBaseActionEnums> CharacterActions;

	UPROPERTY()
	FBaseStructs BaseVariables;

	UPROPERTY()
	TEnumAsByte<EBasePermittedActionEnums> PossibleAction;
	
	UPROPERTY()
	FTimerHandle GeneralTimer;
	UPROPERTY()
	FTimerHandle ActionTimer;
	UPROPERTY()
	FTimerHandle ButtonPressTimer;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveSide(float Value);
	void ForwardCameraAngle(float Value);
	void SideCameraAngle(float Value);
	
	void ActiveJump_Pressed();
	void ActiveJump_Released();
	
	void ActiveAction_Pressed();
	void ActiveAction_Released();
	
	void ChangeSkateboardUse_Pressed();
	void ChangeSkateboardUse_Released();

	void SpeedUP_Pressed();
	void SpeedUP_Released();

	void SpeedDown_Pressed();
	void SpeedDown_Released();
	
	void PauseGame_Pressed();
	void PauseGame_Released();
	
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

	UFUNCTION(BlueprintCallable)
	virtual FBaseStructs ReturnCharacterInfo() override;
	UFUNCTION(BlueprintCallable)
	virtual EBaseCharacterStates ReturnCharacterStates() override;
	UFUNCTION(BlueprintCallable)
	virtual EBaseActionEnums ReturnCharacterActions() override;
};
