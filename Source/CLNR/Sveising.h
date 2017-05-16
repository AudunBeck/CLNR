// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Gunk.h"
#include "GunkSpawner.h"
#include "PowerSwitch.h"
#include "PowerCable.h"
#include "Sveising.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API ASveising : public AGunk
{
	GENERATED_BODY()
	
public:

	ASveising();

	UPROPERTY(EditAnywhere, Category = "Powered to")
		APoweredItem* TargetActor;

	UPROPERTY(EditAnywhere, Category = "Powered to")
		TArray<APowerCable*> CableArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* OurAnimatedComponent;

	UPROPERTY(EditAnywhere)
		UAnimSequence* AnimOpen;

	UPROPERTY(EditAnywhere)
		UAnimSequence* AnimClosed;

	UPROPERTY(EditAnywhere)
		APowerSwitch* ConnectedSwitch;


	bool Done = false; //Quick fix.
	
	
	virtual void PlayerInteracting(float DeltaTime) override;
	virtual void PlayerDone() override;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) override;
	virtual void EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)override;
};
