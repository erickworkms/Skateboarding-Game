#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ABaseCharacter::DefineSpeedValues()
{
	if (BaseVariables.IsUsingSkateboard)
	{
		if (DecreaseSpeed)
		{
			BaseVariables.MaxSpeed = 0;
		}
		else if (IncreaseSpeed)
		{
			BaseVariables.MaxSpeed = 1000;
		}
		else
		{
			BaseVariables.MaxSpeed = 700;
		}
	}
	else if (!BaseVariables.IsUsingSkateboard)
	{
		if (RunActived)
		{
			BaseVariables.MaxSpeed = 700;
		}
		else
		{
			BaseVariables.MaxSpeed = 300;
		}
	}

	if ((RunActived && BaseVariables.Speed <= 0) || BaseVariables.IsUsingSkateboard)
	{
		RunActived = false;
	}

	GetCharacterMovement()->MaxWalkSpeed = BaseVariables.MaxSpeed;
	BaseVariables.IsCharacterMoving = (GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
		+ GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y) > 0;
	BaseVariables.Speed = FMath::FInterpTo(BaseVariables.Speed,
	                                       GetCapsuleComponent()->GetComponentVelocity().GetAbs().X
	                                       + GetCapsuleComponent()->GetComponentVelocity().GetAbs().Y, 0.01f, 10.f);


	FVector SocketLocation = GetMesh()->GetSocketLocation("RootSocket");

	FVector RootLocation = GetMesh()->GetComponentToWorld().GetLocation() + FVector(0, 0, 78.5);

	FVector ResultLocation = FVector(SocketLocation.X, SocketLocation.Y, RootLocation.Z);

	FCollisionQueryParams ParametrosColisao;
	ParametrosColisao.AddIgnoredActor(this);

	FHitResult CheckContactRoot;
	GetWorld()->LineTraceSingleByChannel(
		CheckContactRoot,
		ResultLocation,
		ResultLocation - FVector(0, 0, 151),
		ECC_Visibility,
		ParametrosColisao);


	// FQuat VectorRotatorRootUP = FQuat::FindBetweenVectors(FVector::UpVector, CheckContactRoot.ImpactNormal);
	// float rotatorRootUp =FQuatRotationMatrix(VectorRotatorRootUP).Rotator().Pitch;
	// RootRotation = FRotator(UKismetMathLibrary::FInterpTo(RootRotation.Pitch,rotatorRootUp,0.01,5.0f),0,0);
	// FRotator RootRotationYaw = GetControlRotation() - RootRotation;
	// RootRotationYaw.Normalize();
	//
	// GetMesh()->SetWorldRotation(FRotator(RootRotation.Pitch,
	// 	GetMesh()->GetComponentRotation().Yaw + RootRotationYaw.Yaw - GetControlRotation().Yaw,
	// 	GetMesh()->GetComponentRotation().Roll));
	
	if (ButtonIsPressed && PossibleAction == LadderSliddingPermitted)
	{
		if (IsValid(WallDetected))
		{
			GetCapsuleComponent()->SetWorldRotation(FRotator(GetCapsuleComponent()->GetComponentRotation().Pitch,
			                                                 WallDetected->GetRootComponent()->GetComponentRotation().Yaw,
			                                                 GetCapsuleComponent()->GetComponentRotation().Roll));
		}
	}
}
