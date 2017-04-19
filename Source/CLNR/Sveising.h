// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gunk.h"
#include "GunkSpawner.h"
#include "Sveising.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API ASveising : public AGunk
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Powered to")
		AGunkSpawner* TargetActor;

	
	
	virtual void PlayerInteracting(float DeltaTime) override;
	virtual void PlayerDone() override;
	
};
