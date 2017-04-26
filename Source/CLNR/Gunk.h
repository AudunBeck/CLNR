// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Gunk.generated.h"

UCLASS()
class CLNR_API AGunk : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComponent;

	UFUNCTION()
		virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		virtual void EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnywhere)
		float TimeLeft = 2;

	float TotalTime;

	UPROPERTY(EditAnywhere)
		int Type = 1; //What type of kit needs to be used.

	virtual void PlayerInteracting(float DeltaTime);
	virtual void PlayerDone();




	bool OverlapPlayer = false;
	
	
};
