// Written by Adam Weesner @2020
#include "MainMenu.h"
#include "Components/Button.h"

bool UMainMenu::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!BindButtons()) return false;

	return true;
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
}

void UMainMenu::JoinOnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Join clicked!"));
}
