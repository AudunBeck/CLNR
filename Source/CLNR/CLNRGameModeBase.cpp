// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.h"

void ACLNRGameModeBase::BeginPlay()
{

	UWorld* World = GetWorld();
	if (World)
	{
		
		FVector SpawnLocation = FVector((0.f), (0.f), (0.f));
		ACleaner *tempPlayer = World->SpawnActor<ACleaner>(CleanerBlueprint, SpawnLocation, FRotator::ZeroRotator);
		tempPlayer->GameModePointer = this;
		tempPlayer->PlaceInArray = ArraySize;
		PlayerArray.Add(tempPlayer);
		ArraySize++;
	}

}

void ACLNRGameModeBase::ChangePower(float Value)
{
	CurrentPower -= Value;
	UE_LOG(LogTemp, Warning, TEXT("Power is set to %f"), CurrentPower);
	if (CurrentPower <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Power left!"));
		UGameplayStatics::OpenLevel(GetWorld(), FName("AudunMap"));
		
	}
}

