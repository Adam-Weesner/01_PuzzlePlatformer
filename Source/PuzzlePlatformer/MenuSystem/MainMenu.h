// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface_MainMenu.h"
#include "MainMenu.generated.h"

/**
 * 
 */
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
	virtual void HostOnClicked();

	UFUNCTION()
	virtual void JoinOnClicked();

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:
	bool BindButtons();

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	IInterface_MainMenu* MenuInterface;
	APlayerController* PlayerController;
};
