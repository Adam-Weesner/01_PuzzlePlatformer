// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "UMGHandler.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMER_API AUMGHandler : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WBP_MainMenu;

private:
	APlayerController* PlayerController;
};
