#include "SkateboardGameMode.h"

#include "GameSettings/Controller/SkateboardController.h"
#include "Kismet/GameplayStatics.h"


ASkateboardGameMode::ASkateboardGameMode(): Hud(nullptr)
{
	static ConstructorHelpers::FClassFinder<AHUD> PlayerHUDClass(TEXT("/Game/UI/SkateboardHUD"));
	if (PlayerHUDClass.Succeeded())
	{
		HUDClass = PlayerHUDClass.Class;
	}
	PlayerControllerClass = ASkateboardController::StaticClass();
	DefaultPawnClass = ABaseCharacter::StaticClass();
}

void ASkateboardGameMode::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);

	if (Controller)
	{
		Controller->bShowMouseCursor = true;
		Controller->DefaultMouseCursor = EMouseCursor::Crosshairs;
	}
}
