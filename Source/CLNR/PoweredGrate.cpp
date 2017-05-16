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
	if (GettingPower && TurnedOn)
	{
		MovePoint = -300;
	}
}

void APoweredGrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation() != FVector(0, 0, MovePoint))
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Z -= DeltaTime*Speed;
		if (CurrentLocation.Z <= MovePoint)
		{
			CurrentLocation.Z = MovePoint;
		}
		SetActorLocation(CurrentLocation);

	}

}


