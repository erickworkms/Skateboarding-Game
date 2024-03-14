#include "Characters/BaseCharacter/BaseCharacter.h"
// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &ABaseCharacter::MoveSide).bExecuteWhenPaused = true;
	
	PlayerInputComponent->BindAxis(TEXT("ForwardCameraAngle"), this, &ABaseCharacter::ForwardCameraAngle);
	PlayerInputComponent->BindAxis(TEXT("SideCameraAngle"), this, &ABaseCharacter::SideCameraAngle);
	
	PlayerInputComponent->BindAction(TEXT("ActiveJump"), IE_Pressed, this, &ABaseCharacter::ActiveJump_Pressed).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAction(TEXT("ActiveJump"), IE_Released, this, &ABaseCharacter::ActiveJump_Released).bExecuteWhenPaused = true;
	
	PlayerInputComponent->BindAction(TEXT("ActiveAction"), IE_Pressed, this,
									 &ABaseCharacter::ActiveAction_Pressed);
	PlayerInputComponent->BindAction(TEXT("ActiveAction"), IE_Released, this,
									 &ABaseCharacter::ActiveAction_Released);
	
	PlayerInputComponent->BindAction(TEXT("ChangeSkateboardUse"), IE_Pressed, this,
									 &ABaseCharacter::ChangeSkateboardUse_Pressed);
	PlayerInputComponent->BindAction(TEXT("ChangeSkateboardUse"), IE_Released, this,
									 &ABaseCharacter::ChangeSkateboardUse_Released);
	
	PlayerInputComponent->BindAction(TEXT("SpeedUP"), IE_Pressed, this, &ABaseCharacter::SpeedUP_Pressed);
	PlayerInputComponent->BindAction(TEXT("SpeedUP"), IE_Released, this, &ABaseCharacter::SpeedUP_Released);

	PlayerInputComponent->BindAction(TEXT("SpeedDown"), IE_Pressed, this, &ABaseCharacter::SpeedDown_Pressed);
	PlayerInputComponent->BindAction(TEXT("SpeedDown"), IE_Released, this, &ABaseCharacter::SpeedDown_Released);

	PlayerInputComponent->BindAction(TEXT("ControllerMap"), IE_Pressed, this, &ABaseCharacter::ControllerMap_Pressed).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAction(TEXT("ControllerMap"), IE_Released, this, &ABaseCharacter::ControllerMap_Released).bExecuteWhenPaused = true;

	PlayerInputComponent->BindAction(TEXT("PauseGame"), IE_Pressed, this, &ABaseCharacter::PauseGame_Pressed).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAction(TEXT("PauseGame"), IE_Released, this, &ABaseCharacter::PauseGame_Released).bExecuteWhenPaused = true;
}