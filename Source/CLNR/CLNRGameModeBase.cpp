// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.h"
#include "MyGameInstance.h"


void ACLNRGameModeBase::ChangePower(float Value)
{	
	if ((CurrentPower - Value) <= 0) //If the next value of current power is 0 or lower, calculate the points that the player should get and put them as score.
	{
		UE_LOG(LogTemp, Warning, TEXT("No Power left!"));
		
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = ceil((CurrentPoints / MaxPoints) * 10);
		Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn())->CanMove = false;
		Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn())->EndingLevel = true;
		return;

	}
	

	if (CurrentPoints == MaxPoints) //If the player cleans everything in the level, give maximum score, and add the power as a highscore.W
	{
		Cast<UMyGameInstance>(GetGameInstance())->GameScore[LevelNumber] = 10;

		if (CurrentPower > Cast<UMyGameInstance>(GetGameInstance())->HighScore[LevelNumber]) //If current power is higher than the last highscore, change it.
		{
			Cast<UMyGameInstance>(GetGameInstance())->HighScore[LevelNumber] = CurrentPower;
		}
		Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn())->CanMove = false;
		Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn())->EndingLevel = true;

	}

	CurrentPower -= Value;//Removes power from the currentpower
}


