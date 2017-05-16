// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.h"
#include "MyGameInstance.h"


void ACLNRGameModeBase::ChangePower(float Value)
{
	if ((CurrentPower - Value) <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Power left!"));
		UGameplayStatics::OpenLevel(GetWorld(), FName("Cafe"));
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = ceil((CurrentPoints/MaxPoints)*10);
		return;
			
	}
	CurrentPower -= Value;

	if (CurrentPoints == MaxPoints)
	{
		UE_LOG(LogTemp, Warning, TEXT("You won, script for winning goes here!"));
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = 10;
		UGameplayStatics::OpenLevel(GetWorld(), FName("Cafe"));

	}
	
}

