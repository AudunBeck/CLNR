// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	 //Save game, just contains the points.
	UPROPERTY(VisibleAnywhere, Category = Basic)
		int GameScore[3];

	UPROPERTY(VisibleAnywhere, Category = Basic)
		float HighScore[3];
	
	
};
