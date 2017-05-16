// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PoweredItem.generated.h"

UCLASS()
class CLNR_API APoweredItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoweredItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PowerOn();

	UPROPERTY(EditAnywhere, Category = "Power")
		bool GettingPower = false;

	UPROPERTY(EditAnywhere, Category = "Power")
		bool TurnedOn = false;
	
};
