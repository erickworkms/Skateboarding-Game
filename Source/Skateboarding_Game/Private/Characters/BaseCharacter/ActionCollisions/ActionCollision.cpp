#include "ActionCollision.h"

#include "Characters/BaseCharacter/BaseCharacter.h"


// Sets default values
AActionCollision::AActionCollision()
{
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	if(Collision)
	{
		SetRootComponent(Collision);
	}
}

// Called when the game starts or when spawned
void AActionCollision::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->bHiddenInGame = false;
	Collision->SetVisibility(true);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Collision->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AActionCollision::EnterCollision);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AActionCollision::EndCollision);
}


void AActionCollision::EnterCollision(UPrimitiveComponent* OverlappedComp, AActor* CharacterDetected,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(CharacterDetected) && CharacterDetected != this)
	{
		ABaseCharacter* CharacterFound = Cast<ABaseCharacter>(CharacterDetected);
		if (IsValid(CharacterFound) && CharacterFound->BaseVariables.IsUsingSkateboard)
		{
			CharacterFound->PossibleAction = PossibleAction;
			CharacterFound->BaseVariables.Points += 100;
			CharacterFound->WallDetected = this;
		}
	}
}

void AActionCollision::EndCollision(UPrimitiveComponent* OverlappedComp, AActor* CharacterDetected,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IsValid(CharacterDetected) && CharacterDetected != this)
	{
		ABaseCharacter* CharacterFound = Cast<ABaseCharacter>(CharacterDetected);
		if (IsValid(CharacterFound))
		{
			CharacterFound->PossibleAction = NoActionPermitted;
		}
		
	}
}

