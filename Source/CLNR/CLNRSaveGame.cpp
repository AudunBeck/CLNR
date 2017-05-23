// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRSaveGame.h"

bool CLNRSaveGame::SaveGame(const FString &FullFilePath, FBufferArchive &BinaryData)
{
	if (BinaryData.Num() <= 0)
		return false;

	if (FFileHelper::SaveArrayToFile(BinaryData, *FullFilePath))
	{
		BinaryData.FlushCache();
		BinaryData.Empty();

		UE_LOG(LogTemp, Warning, TEXT("Saved %s successfully!"), *FullFilePath);
		return true;
	}

	BinaryData.FlushCache();
	BinaryData.Empty();
	return false;
}

bool CLNRSaveGame::LoadGame(const FString &FullFilePath, FBufferArchive &BinaryData)
{
	
	if (FFileHelper::LoadFileToArray(BinaryData, *FullFilePath))
	{

		return true;
	}
	return false;
}