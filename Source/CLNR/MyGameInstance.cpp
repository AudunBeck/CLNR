// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	TArray<float> TGameScore;
	TArray<float> THighScore;
	FBufferArchive BinaryData;

	SaveGameInstance = new CLNRSaveGame();
	if (!SaveGameInstance->LoadGame("SaveGame.bin", BinaryData))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not load save file"));
	}
		
	else
	{
		FMemoryReader Ar = FMemoryReader(BinaryData, false);
		Ar << TGameScore;
		Ar << THighScore;

		for (int i = 0; i < TGameScore.Num(); i++)
		{
			GameScore[i] = TGameScore[i];
			HighScore[i] = THighScore[i];
		}
	}	
}

void UMyGameInstance::SaveGame() //Saves a savegame.
{
	FBufferArchive BinaryData;
	TArray<float> TGameScore;
	TArray<float> THighScore;

	for (int i = 0; i < 5; i++)
	{
		TGameScore.Add(GameScore[i]);
		THighScore.Add(HighScore[i]);
	}
	BinaryData << TGameScore << THighScore;

	SaveGameInstance->SaveGame("SaveGame.bin", BinaryData);
}

int UMyGameInstance::GetGameScore(int Slot) //Had to be used so that blueprints could get the scores from the array.
{
	return GameScore[Slot];
}

float UMyGameInstance::GetHighScore(int Slot)
{
	return HighScore[Slot];
}



