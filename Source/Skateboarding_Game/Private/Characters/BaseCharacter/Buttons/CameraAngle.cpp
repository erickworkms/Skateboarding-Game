#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ForwardCameraAngle(float Value)
{
	if (!UGameplayStatics::IsGamePaused(GetWorld()))
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
}

void ABaseCharacter::SideCameraAngle(float Value)
{
	if (!UGameplayStatics::IsGamePaused(GetWorld()))
	{
		AddControllerYawInput(Value);
	}
}
