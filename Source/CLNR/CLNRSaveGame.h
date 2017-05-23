// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class CLNR_API CLNRSaveGame
{
public:

	bool SaveGame(const FString & FullFilePath, FBufferArchive &BinaryData);
	bool LoadGame(const FString & FullFilePath, FBufferArchive &BinaryData);
};
