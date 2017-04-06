// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.h"


void ACLNRGameModeBase::ChangePower(float Value)
{
	if ((CurrentPower - Value) <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Power left!"));
		UGameplayStatics::OpenLevel(GetWorld(), FName("Level_1_Test"));
		return;
			
	}
	CurrentPower -= Value;
	UE_LOG(LogTemp, Warning, TEXT("Power is set to %f"), CurrentPower);

	if (CurrentPoints == MaxPoints)
	{
		UE_LOG(LogTemp, Warning, TEXT("You won, script for winning goes here!"));
		UGameplayStatics::OpenLevel(GetWorld(), FName("Level_2_Test"));
	}
	
}

