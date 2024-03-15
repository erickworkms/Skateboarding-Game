#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseCharacter::ActiveAction_Pressed()
{
	if (!ButtonIsPressed && !UGameplayStatics::IsGamePaused(GetWorld()))
	{
		ButtonIsPressed = true;
		if (CharacterActions == NoAction && CharacterStates == OntheGround)
		{
			if (PossibleAction == LadderSliddingPermitted)
			{
				CharacterActions = LadderSlidding;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
				GetWorldTimerManager().SetTimer(
					ActionContinueTimer,
					this,
					&ABaseCharacter::ExecActionContinue,
					3, false);
			}
			else if (PossibleAction == BackJumpPermitted)
			{
				CharacterActions = BackJump;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
			}
			else if (PossibleAction == GroundFeintPermitted)
			{
				CharacterActions = GroundFeint;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
				GetWorldTimerManager().SetTimer(
					ActionContinueTimer,
					this,
					&ABaseCharacter::ExecActionContinue,
					1, false);
			}
		}
		else if (CharacterStates == FallingIntheAir)
		{
			if (PossibleAction == WallSliddingPermitted)
			{
				CharacterActions = WallSlidding;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
				GetWorldTimerManager().SetTimer(
					ActionContinueTimer,
					this,
					&ABaseCharacter::ExecActionContinue,
					1, false);
			}
			else if (PossibleAction == LadderSliddingPermitted)
			{
				CharacterActions = LadderSlidding;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
				GetWorldTimerManager().SetTimer(
					ActionContinueTimer,
					this,
					&ABaseCharacter::ExecActionContinue,
					3, false);
			}
			else if (PossibleAction == WallRollPermitted)
			{
				CharacterActions = WallRoll;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;
			}
			else if (PossibleAction == AirFeintPermitted)
			{
				CharacterActions = AirFeint;
				BaseVariables.Points += 10;
				ReceivePointsContinue = true;

				GetWorldTimerManager().SetTimer(
					ActionContinueTimer,
					this,
					&ABaseCharacter::ExecActionContinue,
					0.5, false);
			}
		}
	}
}

void ABaseCharacter::ActiveAction_Released()
{
	ButtonIsPressed = false;
}

void ABaseCharacter::ExecutePointTimer()
{
	if (ReceivePointsContinue)
	{
		BaseVariables.Points += 1;
	}
}

void ABaseCharacter::ExecActionContinue()
{
	CharacterActions = NoAction;
	ReceivePointsContinue = false;
}
