// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LevelVariables.generated.h"

UCLASS()
class CLNR_API ALevelVariables : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		int LevelNumber;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
	
};
