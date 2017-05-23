// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BackgroundShip.generated.h"

UCLASS()
class CLNR_API ABackgroundShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackgroundShip();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float RotationSpeed = 100;

	UPROPERTY(EditAnywhere)
		FRotator Direction;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	
	
};
