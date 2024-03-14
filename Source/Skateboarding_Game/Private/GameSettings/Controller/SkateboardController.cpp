#include "SkateboardController.h"
#include "Delegates/DelegateSignatureImpl.inl"



void ASkateboardController::BeginPlay()
{
	Super::BeginPlay();
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	SetTickableWhenPaused(true);
}
