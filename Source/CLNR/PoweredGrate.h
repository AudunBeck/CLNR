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
	float MovePoint = 0;
		
public:

	virtual void PowerOn()override;
	virtual void Tick(float DeltaTime)override;

	UPROPERTY(EditAnywhere)
		float Speed = 10;

	UPROPERTY(EditAnywhere)
		float WhereToMove = -300;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	
};
