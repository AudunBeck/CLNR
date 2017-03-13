// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "CLNRGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API ACLNRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


	
public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		int MaxPoints = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		int CurrentPoints = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float MaxPower = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float CurrentPower = 0;

	void ChangePower(float Value);

	UPROPERTY(EditAnywhere, Category = "Spawning Player")
		TSubclassOf<class ACleaner> CleanerBlueprint;

	TArray<ACleaner*> PlayerArray;
	int ArraySize;


};
