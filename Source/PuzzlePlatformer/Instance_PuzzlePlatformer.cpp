// Written by Adam Weesner @2020
#include "Instance_PuzzlePlatformer.h"
#include "Engine/Engine.h"
#include "Misc/Paths.h" 	
#include "GameFramework/PlayerController.h"

UInstance_PuzzlePlatformer::UInstance_PuzzlePlatformer(const FObjectInitializer& ObjectInitializer)
{
}

void UInstance_PuzzlePlatformer::Init()
{
}

void UInstance_PuzzlePlatformer::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine)) return;

	FString output = "Hosting";
	Engine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, output);

	LoadMap();
}

void UInstance_PuzzlePlatformer::Join(const FString address)
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;
	FString output = "Joining: " + address;

	Engine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, output);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController)) return;

	PlayerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}

void UInstance_PuzzlePlatformer::NextMap()
{
	LevelIndex++;

	if (LevelIndex >= Levels.Num())
	{
		LevelIndex = 0;
	}

	LoadMap();
}

void UInstance_PuzzlePlatformer::LoadMap()
{
	UWorld* World = GetWorld();
	if (!ensure(World)) return;

	FString LevelPath = Levels[LevelIndex].GetAssetName();
	World->ServerTravel(LevelPath + "?listen");
}
