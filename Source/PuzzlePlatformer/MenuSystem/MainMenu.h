// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface_MainMenu.h"
#include "MainMenu.generated.h"

class UButton;
class UWidgetSwitcher;
class UEditableTextBox;

UCLASS()
class PUZZLEPLATFORMER_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IInterface_MainMenu* InMenuInterface);

	void Setup();

protected:
	virtual bool Initialize() override;

	UFUNCTION()
	virtual void OnHostButtonClicked();

	UFUNCTION()
	virtual void OnJoinButtonClicked();

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:
	bool BindButtons();

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	// Main menu screen
	UFUNCTION()
	void OnJoinGameButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinMenuButton;

	// Join game screen
	UFUNCTION()
	void OnBackButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	IInterface_MainMenu* MenuInterface;
	APlayerController* PlayerController;
};
