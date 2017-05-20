// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	int GameScore[3]{ 0,0,0 };
	float HighScore[3]{ 0,0,0 };
	
	UFUNCTION(BlueprintCallable)
		void LoadSaveGame();
	
	UFUNCTION(BlueprintCallable)
		void SaveGame();
	
};
