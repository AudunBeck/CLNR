// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PoweredItem.h"
#include "PoweredGrate.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API APoweredGrate : public APoweredItem
{
	GENERATED_BODY()
public:
	APoweredGrate();

private:
	FVector MovePoint;
		
public:

	virtual void PowerOn()override;
	virtual void Tick(float DeltaTime)override;

	UPROPERTY(EditAnywhere)
		float Speed = 10;

	UPROPERTY(EditAnywhere)
		FVector WhereToMove;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	
	UPROPERTY(EditAnywhere)
		int Direction; // 1 is X, 2 is Y and 3 is Z
};
