// Written by Adam Weesner @2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_UMGHandler.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_UMGHandler : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PUZZLEPLATFORMER_API IInterface_UMGHandler
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Host() = 0;
};
