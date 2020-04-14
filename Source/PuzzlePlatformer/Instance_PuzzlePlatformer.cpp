// Written by Adam Weesner @2020
#include "Instance_PuzzlePlatformer.h"
#include "Engine/Engine.h"

UInstance_PuzzlePlatformer::UInstance_PuzzlePlatformer(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor"));
}

void UInstance_PuzzlePlatformer::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init"));
}

void UInstance_PuzzlePlatformer::Host()
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;

	Engine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Hosting"));
}

void UInstance_PuzzlePlatformer::Join(const FString address)
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;
	FString output = "Joining: " + address;

	Engine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, output);
}
