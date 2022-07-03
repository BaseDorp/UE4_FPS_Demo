// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//RootComponent = Mesh;

	Mesh->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Allows the updated movement to be shown on the client as well
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		GlobalStartLocation = GetActorLocation();
		// takes the transform and transforms the position to a world location
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	}
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (activeTriggers > 0)
	{
		// Only updates the movement of the actor on the server
		if (HasAuthority())
		{
			FVector dir = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			FVector loc = GetActorLocation();
			loc += movementSpeed * DeltaTime * dir;
			SetActorLocation(loc);

			if (GlobalStartLocation.PointsAreNear(GetActorLocation(), GlobalTargetLocation, 5))
			{
				FVector Swap = GlobalTargetLocation;
				GlobalTargetLocation = GlobalStartLocation;
				GlobalStartLocation = Swap;
			}
			
		}
	}

	
}

void AMovingPlatform::AddActiveTrigger()
{
	++activeTriggers;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (activeTriggers > 0) --activeTriggers;
}