// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DisapearingBoxes.generated.h"

UCLASS()
class CLNR_API ADisapearingBoxes : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisapearingBoxes();

protected:
	// Called when the game starts or when spawned

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		int WhenToRemove = 6;
};
