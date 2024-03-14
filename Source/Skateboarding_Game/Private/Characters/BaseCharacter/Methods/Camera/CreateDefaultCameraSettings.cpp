#include "Characters/BaseCharacter/BaseCharacter.h"

void ABaseCharacter::CreateDefaultCameraSettings()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

	CharacterCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	CharacterCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	CharacterCamera->bUsePawnControlRotation = false;
	CharacterCamera->GetCollisionResponseToChannel(ECollisionChannel::ECC_Camera);

	//Assign SpringArm class variables.
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 20.0f;

	SpringArm->bDoCollisionTest = false;
	SpringArm->ProbeSize = 15;
	SpringArm->ProbeChannel = ECC_Camera;

	//Take control of the default Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


