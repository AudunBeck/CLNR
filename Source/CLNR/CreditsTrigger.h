// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LevelSequencePlayer.h"
#include "MovieScene.h"
#include "MyGameInstance.h"
#include "CreditsTrigger.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLNR_API UCreditsTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCreditsTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	UPROPERTY(EditAnywhere)
	AActor* Character;

	ULevelSequencePlayer* SequencePlayer;

	UPROPERTY(EditAnywhere)
	AActor* CameraActor;

	UPROPERTY(EditAnywhere)
	AActor* StaticActor;

	UPROPERTY(EditAnywhere)
	float TimeToTwitchToMainMenu = 40.0f;

	float WaitTimer = 0.f;

	bool isPlaying = false;

	UMyGameInstance* GameInstance = nullptr;
};
