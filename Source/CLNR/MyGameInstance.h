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
	int GameScore[3]{ 0,0,0 }; //Keeps the score per level.
	float HighScore[3]{ 0,0,0 }; //Keeps the Highscore (if the player cleans everything this is the power the player had left).
	
	UFUNCTION(BlueprintCallable) //Makes the function callable in blueprint
		void LoadSaveGame();
	
	UFUNCTION(BlueprintCallable) //Makes the function callable in blueprint
		void SaveGame();

	UFUNCTION(BlueprintCallable)
		int GetGameScore(int Slot);

	UFUNCTION(BlueprintCallable)
		float GetHighScore(int Slot);
	
};
