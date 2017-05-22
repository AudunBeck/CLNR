// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PowerCable.generated.h"

UCLASS()
class CLNR_API APowerCable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerCable();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* OurVisibleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	void SwitchPower(bool GettingPowered);

	UPROPERTY(EditAnywhere, Category = "MatChange") //Stores the material it should.
		UMaterial* On;

	UPROPERTY(EditAnywhere, Category = "MatChange")
		UMaterial* Off;

	UPROPERTY(EditAnywhere)
		bool CanBePowered = false;

	UPROPERTY(EditAnywhere) //What material to change, had to be added because of inconsistency of what material to change when powered.
		int MaterialToChange = 0;
	
	
};
