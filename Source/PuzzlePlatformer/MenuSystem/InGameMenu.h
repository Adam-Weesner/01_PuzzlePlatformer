// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameMenu.generated.h"

class UButton;

UCLASS()
class PUZZLEPLATFORMER_API UInGameMenu : public UUserWidget
{
	GENERATED_BODY()


public:
	void Setup();
	void TearDown();

protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	
private:
	bool BindWidgets();

	UFUNCTION()
	void OnBackButtonReleased();

	UFUNCTION()
	void OnMainMenuButtonReleased();

	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MainMenuButton;

	APlayerController* PlayerController;
};
