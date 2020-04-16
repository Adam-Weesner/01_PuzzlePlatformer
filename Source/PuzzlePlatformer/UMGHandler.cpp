// Written by Adam Weesner @2020
#include "UMGHandler.h"
#include "Kismet/GameplayStatics.h"

void AUMGHandler::BeginPlay()
{
	Super::BeginPlay();
}

void AUMGHandler::LoadMenu()
{
	if (!ensure(WBP_MainMenu)) return;

	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (!ensure(PlayerController)) return;

	UUserWidget* Menu = CreateWidget(PlayerController, WBP_MainMenu);
	if (!ensure(Menu)) return;

	Menu->bIsFocusable = true;
	Menu->AddToViewport();

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(Menu->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);

	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(inputMode);
}