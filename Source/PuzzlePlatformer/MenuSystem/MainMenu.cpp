// Written by Adam Weesner @2020
#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!BindButtons()) return false;

	return true;
}

void UMainMenu::Setup()
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

void UMainMenu::SetMenuInterface(IInterface_MainMenu* InMenuInterface)
{
	this->MenuInterface = InMenuInterface;
}

bool UMainMenu::BindButtons()
{
	if (!ensure(HostButton)) return false;
	if (!ensure(JoinMenuButton)) return false;
	if (!ensure(JoinButton)) return false;
	if (!ensure(BackButton)) return false;

	HostButton->OnReleased.AddDynamic(this, &UMainMenu::OnHostButtonClicked);
	JoinMenuButton->OnReleased.AddDynamic(this, &UMainMenu::OnJoinGameButtonClicked);
	JoinButton->OnReleased.AddDynamic(this, &UMainMenu::OnJoinButtonClicked);
	BackButton->OnReleased.AddDynamic(this, &UMainMenu::OnBackButtonClicked);

	return true;
}

void UMainMenu::OnHostButtonClicked()
{
	if (!ensure(MenuInterface)) return;
	
	MenuInterface->Host();
}

void UMainMenu::OnJoinGameButtonClicked()
{
	if (!ensure(MenuSwitcher)) return;
	if (!ensure(JoinMenu)) return;

	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::OnJoinButtonClicked()
{
	if (!ensure(MenuInterface)) return;

	const FString &ipAddressInput = IPAddressTextBox->GetText().ToString();

	if (ipAddressInput.IsEmpty()) return;

	MenuInterface->Join(ipAddressInput);
}

void UMainMenu::OnBackButtonClicked()
{
	if (!ensure(MenuSwitcher)) return;
	if (!ensure(MainMenu)) return;

	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	FInputModeGameOnly inputMode;
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(inputMode);
	RemoveFromViewport();
}
