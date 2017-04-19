// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Sveising.h"
#include "GunkSpawner.h"

 
void ASveising::PlayerInteracting(float DeltaTime)
{
	//Kjør animasjon eller partikler
	if (!TargetActor->TurnedOn && TargetActor != nullptr)
	{
		TimeLeft -= DeltaTime;
		OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
	}
	
}

void ASveising::PlayerDone()
{
	if (TargetActor->IsA(AGunkSpawner::StaticClass()) && TargetActor != nullptr)
	{
		TargetActor->GettingPower = true;
		Destroy();
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no target actor on Sveising %i"), 0);
	}
}
