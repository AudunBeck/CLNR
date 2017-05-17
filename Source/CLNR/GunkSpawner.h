// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PoweredItem.h"
#include "GunkSpawner.generated.h"

UCLASS()
class CLNR_API AGunkSpawner : public APoweredItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunkSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* OurAnimatedComponent;

	UPROPERTY(EditAnywhere)
		UAnimSequence* AnimOpen;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	UPROPERTY(EditAnywhere, Category = "Spawning")
		int GunkAmount = 4;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float RandomRangeTop = 50;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float RandomRangeBot = -50;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float DistanceToFloor = -20;

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AGunk> GunkBlueprint;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		bool ContainGunk = true;


	UPROPERTY(EditAnywhere, Category = "TextureChange")
		UMaterial* Filled;

	UPROPERTY(EditAnywhere, Category = "TextureChange")
		UMaterial* Empty;

	
	virtual void PowerOn() override;

	bool OverlapPlayer = false;
};
