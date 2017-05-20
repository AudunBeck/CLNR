// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "LevelVariables.h"
#include "CLNRGameModeBase.h"


// Called when the game starts or when spawned
void ALevelVariables::BeginPlay()
{
	Super::BeginPlay();
	ACLNRGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ACLNRGameModeBase>();
	GameMode->LevelNumber = LevelNumber;
	GameMode->TimeToStop = TimeToStop;
	GameMode->MaxPower = StartingPower;
	GameMode->CurrentPower = GameMode->MaxPower;
}

