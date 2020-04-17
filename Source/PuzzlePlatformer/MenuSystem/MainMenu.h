// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "Interface_MainMenu.h"
#include "MainMenu.generated.h"

class UButton;
class UWidgetSwitcher;
class UEditableTextBox;

UCLASS()
class PUZZLEPLATFORMER_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IInterface_MainMenu* InMenuInterface);

protected:
	UFUNCTION()
	virtual void OnHostButtonReleased();

	UFUNCTION()
	virtual void OnJoinButtonReleased();

	virtual bool BindWidgets() override;

private:
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	// Main menu screen
	UFUNCTION()
	void OnJoinGameButtonReleased();

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinMenuButton;

	// Join game screen
	UFUNCTION()
	void OnBackButtonReleased();

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	IInterface_MainMenu* MenuInterface;
};
