// Written by Adam Weesner @2020
#include "UMGHandler.h"
#include "Kismet/GameplayStatics.h"
#include "MenuSystem/MainMenu.h"
#include "Instance_PuzzlePlatformer.h"

void AUMGHandler::BeginPlay()
{
	Super::BeginPlay();

	instance = Cast<UInstance_PuzzlePlatformer>(GetGameInstance());
}

void AUMGHandler::LoadMenu()
{
	if (!ensure(WBP_MainMenu)) return;

	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (!ensure(PlayerController)) return;

	Menu = CreateWidget<UMainMenu>(PlayerController, WBP_MainMenu);
	if (!ensure(Menu)) return;

	Menu->Setup();

	Menu->SetMenuInterface(this);
}

void AUMGHandler::Host()
{
	if (!ensure(instance)) return;
	
	instance->Host();
}

void AUMGHandler::Join(FString ipAddress)
{
	if (!ensure(instance)) return;

	instance->Join(ipAddress);
}
