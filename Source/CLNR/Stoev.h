// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gunk.h"
#include "Stoev.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API AStoev : public AGunk
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


	virtual void Tick(float DeltaTime) override;
	virtual void PlayerInteracting(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float DistanceNeeded = 150;

	UPROPERTY(EditAnywhere)
		float Speed = 0.5;
	
	
};
