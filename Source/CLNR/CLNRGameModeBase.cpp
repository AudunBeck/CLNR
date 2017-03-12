// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"

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

