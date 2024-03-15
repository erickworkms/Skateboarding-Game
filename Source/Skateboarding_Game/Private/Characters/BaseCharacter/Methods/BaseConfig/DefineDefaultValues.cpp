#include "Characters/BaseCharacter/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameSettings/Controller/SkateboardController.h"

void ABaseCharacter::DefineDefaultValues()
{
	BaseVariables.Direction = 0;
	BaseVariables.Points = 0;
	BaseVariables.Speed = 0;
	BaseVariables.AnimationSpeed = 1;
	BaseVariables.CharacterAngle = 0;
	BaseVariables.MaxSpeed = 0;
	BaseVariables.ActionIsActived = false;
	BaseVariables.IsCharacterMoving = false;
	BaseVariables.IsUsingSkateboard = false;

	CharacterStates = OntheGround;
	CharacterActions = NoAction;
	PossibleAction = NoActionPermitted;

	SkateboardMesh->AttachToComponent(GetMesh(),
					 FAttachmentTransformRules::SnapToTargetIncludingScale, "SkateboardSocket");
	SkateboardMesh->SetRelativeLocationAndRotation(FVector(0, 0, 0),
										  FRotator(0, 0, 0), false, nullptr);
	SkateboardMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->AirControlBoostMultiplier = 1;
	GetCharacterMovement()->AirControlBoostVelocityThreshold = 1000;
	GetCharacterMovement()->AirControl = 0.5f;
	GetCharacterMovement()->GravityScale = 1.f;
	GetCharacterMovement()->GroundFriction = 1000.f;
	GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = true;


	GetController()->SetTickableWhenPaused(true);

	ASkateboardController* SkateController = Cast<ASkateboardController>(GetController());
	if (SkateController)
	{
		SkateGameMode = Cast<ASkateboardGameMode>(SkateController->GetWorld()->GetAuthGameMode());
	}
}


