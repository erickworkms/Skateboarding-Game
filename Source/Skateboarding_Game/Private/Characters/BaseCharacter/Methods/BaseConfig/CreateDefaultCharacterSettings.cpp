#include "Characters/BaseCharacter/BaseCharacter.h"
#include "Components/CapsuleComponent.h"

void ABaseCharacter::CreateDefaultCharacterSettings()
{
	GetCapsuleComponent()->InitCapsuleSize(29.0f, 76.0f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		MeshContainer(TEXT("SkeletalMesh'/Game/Character/Models/BaseCharacter.BaseCharacter'"));
	if (MeshContainer.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshContainer.Object);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -75));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		GetMesh()->SetWorldScale3D(FVector(0.70f, 0.70f, 0.70f));
	}
	static ConstructorHelpers::FObjectFinder<UClass>
		AnimBlueprint(TEXT("AnimBlueprint'/Game/Character/Models/BaseCharacterAnimBlueprint.BaseCharacterAnimBlueprint_C'"));
	GetMesh()->SetAnimInstanceClass(AnimBlueprint.Object);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
	MeshSkateboard(TEXT("SkeletalMesh'/Game/Assets/Skateboard/Skateboard.Skateboard'"));
	SkateboardMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkateboardMesh"));
	SkateboardMesh->SetSkeletalMesh(MeshSkateboard.Object);
	SkateboardMesh->SetupAttachment(GetMesh());
}
