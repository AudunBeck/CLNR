// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "PoweredGrate.h"

APoweredGrate::APoweredGrate()
{
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

void APoweredGrate::PowerOn()
{
	if (GettingPower && TurnedOn) //If it is powered on, and getting power, change where this object should move to.
	{
		MovePoint = WhereToMove;
	}
}

void APoweredGrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation() != FVector(0, 0, MovePoint)) //If the object is not where it should be, move it in that direction.
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Z -= DeltaTime*Speed;
		if (CurrentLocation.Z <= MovePoint) //If it is about to pass the point it should move to, move it to the point it should move to.
		{
			CurrentLocation.Z = MovePoint;
		}
		SetActorLocation(CurrentLocation);

	}

}


