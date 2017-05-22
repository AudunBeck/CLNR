// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "MyGameInstance.h"

void UMyGameInstance::LoadSaveGame() //Loads a save game, if none was found it makes a new one.
{
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	for (int i = 0; i <= 3; i++)
	{
		GameScore[i] = LoadGameInstance->GameScore[i];
		HighScore[i] = LoadGameInstance->HighScore[i];
	}
	
}

void UMyGameInstance::SaveGame() //Saves a savegame.
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	for (int i = 0; i <= 3; i++)
	{
		SaveGameInstance->GameScore[i] = GameScore[i];
		SaveGameInstance->HighScore[i] = HighScore[i];
	}
}

int UMyGameInstance::GetGameScore(int Slot) //Had to be used so that blueprints could get the scores from the array.
{
	return GameScore[Slot];
}

float UMyGameInstance::GetHighScore(int Slot)
{
	return HighScore[Slot];
}



