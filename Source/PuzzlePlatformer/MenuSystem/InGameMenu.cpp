// Written by Adam Weesner @2020
#include "InGameMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UInGameMenu::Setup()
{
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (!ensure(PlayerController)) return;

	bIsFocusable = true;
	AddToViewport();

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);

	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(inputMode);
}

void UInGameMenu::TearDown()
{
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (!ensure(PlayerController)) return;

	RemoveFromViewport();

	FInputModeGameOnly inputMode;

	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(inputMode);
}

bool UInGameMenu::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!BindWidgets()) return false;

	return true;
}

void UInGameMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	TearDown();
}

bool UInGameMenu::BindWidgets()
{
	if (!ensure(BackButton)) return false;
	if (!ensure(MainMenuButton)) return false;

	BackButton->OnReleased.AddDynamic(this, &UInGameMenu::OnBackButtonReleased);
	MainMenuButton->OnReleased.AddDynamic(this, &UInGameMenu::OnMainMenuButtonReleased);

	return true;
}

void UInGameMenu::OnBackButtonReleased()
{
	TearDown();
}

void UInGameMenu::OnMainMenuButtonReleased()
{
}
