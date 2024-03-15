#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::MoveForward(float Value)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding
		&& CharacterActions != BackJump && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		FVector Forward = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

		if (BaseVariables.IsUsingSkateboard)
		{
			if (BaseVariables.Speed > 100)
			{
				AddMovementInput( Forward, Value);
			}
			else
			{
				AddMovementInput(Forward, Value);
			}
			
		}
		else
		{
			AddMovementInput(Forward, Value);
		}
	}
	else if (UGameplayStatics::IsGamePaused(GetWorld()))
	{
		if (Value > 0.9)
		{
			SkateGameMode->Hud->IncreaseButtonValue();
		}
		else if (Value < -0.9)
		{
			SkateGameMode->Hud->DecreaseButtonValue();
		}
	}
}

void ABaseCharacter::MoveSide(float Value)
{
	if (CharacterActions != LadderSlidding && CharacterActions != WallSlidding
		&& CharacterActions != BackJump && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		FVector Side = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Side, Value);
	}
}