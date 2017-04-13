// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GunkSpawner.generated.h"

UCLASS()
class CLNR_API AGunkSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunkSpawner();

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
		int GunkAmount = 4;


public:	

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AGunk> GunkBlueprint;
	
	bool ContainGunk = true;
	bool GettingPower = true;

	void PowerOn();
};
