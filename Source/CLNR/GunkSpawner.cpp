// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "GunkSpawner.h"
#include "Gunk.h"

// Sets default values
AGunkSpawner::AGunkSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}


void AGunkSpawner::PowerOn()
{
	UWorld* World = GetWorld();

	if (GettingPower && TurnedOn)
	{
		if (ContainGunk)
		{
			//Spawn gunk in a general area, or reveal it? Must be gone through with group.
			for (int i = 0; i < GunkAmount; i++)
			{
				FVector SpawnLocation = GetActorLocation() + FVector(FMath::FRandRange(-50.f, 50.f), FMath::FRandRange(-50.f, 50.f), 0);
				AGunk *tempGunk = World->SpawnActor<AGunk>(GunkBlueprint, SpawnLocation, FRotator::ZeroRotator);
			}
			ContainGunk = false;
		}

		else
		{

		}
	}
}