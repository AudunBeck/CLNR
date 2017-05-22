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
	
	if (GetActorLocation() != MovePoint) //If the object is not where it should be, move it in that direction.
	{
		FVector CurrentLocation = GetActorLocation();
		if (MovePoint.X != 0)
		{
			if (MovePoint.X < 0)
			{
				CurrentLocation.X -= DeltaTime*Speed;
				if (CurrentLocation.X <= MovePoint.X) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.X = MovePoint.X;
				}
			}
			else if (MovePoint.X > 0)
			{
				CurrentLocation.X += DeltaTime*Speed;
				if (CurrentLocation.X >= MovePoint.X) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.X = MovePoint.X;
				}
			}
		}

		else if (MovePoint.Y != 0)
		{
			if (MovePoint.Y < 0)
			{
				CurrentLocation.Y -= DeltaTime*Speed;
				if (CurrentLocation.Y <= MovePoint.Y) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.Y = MovePoint.Y;
				}
			}

			else if (MovePoint.Y > 0)
			{
				CurrentLocation.Y += DeltaTime*Speed;
				if (CurrentLocation.Y >= MovePoint.Y) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.Y = MovePoint.Y;
				}
			}
		}

		else if (MovePoint.Z != 0)
		{
			if (MovePoint.Z < 0)
			{
				CurrentLocation.Z -= DeltaTime*Speed;
				if (CurrentLocation.Z <= MovePoint.Z) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.Z = MovePoint.Z;
				}
			}

			else if (MovePoint.Z > 0)
			{
				CurrentLocation.Z += DeltaTime*Speed;
				if (CurrentLocation.Z >= MovePoint.Z) //If it is about to pass the point it should move to, move it to the point it should move to.
				{
					CurrentLocation.Z = MovePoint.Z;
				}
			}
		}
		
		
		SetActorLocation(CurrentLocation);

	}

}


