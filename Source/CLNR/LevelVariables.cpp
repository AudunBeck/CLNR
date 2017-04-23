// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "LevelVariables.h"
#include "CLNRGameModeBase.h"


// Called when the game starts or when spawned
void ALevelVariables::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->LevelNumber = LevelNumber;
	
}

