#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::ForwardCameraAngle(float Value)
{

	float CameraRotation = CharacterCamera->GetSocketRotation("none").Pitch * -1;
	
	if (CameraRotation >= 49 && CameraRotation <= -15)
	{
		AddControllerPitchInput(Value);
	}
	else if (CameraRotation < 49 && Value > 0)
	{
		AddControllerPitchInput(Value);
	}
	else if (CameraRotation > -15 && Value < 0)
	{
		AddControllerPitchInput(Value);
	}
}

void ABaseCharacter::SideCameraAngle(float Value)
{
	AddControllerYawInput(Value);
}