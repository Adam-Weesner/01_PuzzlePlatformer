// Written by Adam Weesner @2020
#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

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
	if (!ensure(JoinButton)) return false;

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostOnClicked);
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinOnClicked);

	return true;
}

void UMainMenu::HostOnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Host clicked!"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinOnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Join clicked!"));
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	FInputModeGameOnly inputMode;
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(inputMode);
	RemoveFromViewport();
}
