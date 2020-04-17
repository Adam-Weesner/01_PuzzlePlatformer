// Written by Adam Weesner @2020
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/Interface_MainMenu.h"
#include "Instance_PuzzlePlatformer.h"
#include "UMGHandler.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMER_API AUMGHandler : public AHUD, public IInterface_MainMenu
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION()
	void Host();

	UFUNCTION()
	void Join(FString ipAddress);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WBP_MainMenu;

private:
	UInstance_PuzzlePlatformer* instance;
	APlayerController* PlayerController;
	class UMainMenu* Menu;
};
