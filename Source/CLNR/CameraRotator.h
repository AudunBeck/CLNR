// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Cleaner.h"
#include "CameraRotator.generated.h"

UCLASS()
class CLNR_API ACameraRotator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraRotator();

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;

	ACleaner* Player;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
		float Rotation = 90;

		float WhereToRotate = 0;

	UPROPERTY(EditAnywhere)
		float CameraRotationSpeed = 10;

	bool Rotating = false;
	bool Inside = false;

	
	
};
