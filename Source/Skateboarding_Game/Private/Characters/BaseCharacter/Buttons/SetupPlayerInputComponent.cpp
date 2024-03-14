#include "Characters/BaseCharacter/BaseCharacter.h"
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