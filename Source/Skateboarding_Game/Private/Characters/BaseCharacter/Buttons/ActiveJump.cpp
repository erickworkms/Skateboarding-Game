#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ActiveJump_Pressed()
{
	if (CharacterStates == OntheGround && CharacterActions != NormalJumping
		&& CharacterActions != SkateJumping && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		if (BaseVariables.IsUsingSkateboard)
		{
			CharacterActions = SkateJumping;
			
			GetWorldTimerManager().SetTimer(
				ButtonPressTimer,
				this,
				&ABaseCharacter::LastVelocityTimer,
				0.01, true);
		}
		else if (!BaseVariables.IsUsingSkateboard)
		{
			CharacterActions = NormalJumping;
		}
		Jump();
		ButtonIsPressed = true;
	}
	else if (UGameplayStatics::IsGamePaused(GetWorld()) && !ButtonIsPressed)
	{
		SkateGameMode->Hud->ChooseOptionHud();
		ButtonIsPressed = true;
	}
}

void ABaseCharacter::ActiveJump_Released()
{
	ButtonIsPressed = false;
}
