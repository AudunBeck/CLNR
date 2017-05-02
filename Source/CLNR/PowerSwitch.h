// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GunkSpawner.h"
#include "PowerCable.h"
#include "PowerSwitch.generated.h"

UCLASS()
class CLNR_API APowerSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerSwitch();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Powered to")
		AGunkSpawner* TargetActor;

	bool SwitchedOn = true;


	UPROPERTY(EditAnywhere)
		UAnimSequence* AnimOn;

	UPROPERTY(EditAnywhere)
		UAnimSequence* AnimOff;

	UPROPERTY(EditAnywhere, Category = "Powered to")
		TArray<APowerCable*> CableArray;
	
	void Activate();
};
