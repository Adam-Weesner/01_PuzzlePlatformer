#include "MovingPlatform.h"
#include <math.h>
#include "Engine/World.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();

		float omega = FMath::Sin(GetWorld()->TimeSeconds);
		Location += Direction * omega;

		SetActorLocation(Location);
	}
}
