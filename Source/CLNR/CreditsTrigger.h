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

	//Reference to the player character	
	UPROPERTY(EditAnywhere)
	AActor* Character;

	//Global variable to the sequence player so it is accessible from anywhere
	ULevelSequencePlayer* SequencePlayer;

	//Reference to the sequence camera
	UPROPERTY(EditAnywhere)
	AActor* CameraActor;

	//Referance to the sequence character
	UPROPERTY(EditAnywhere)
	AActor* StaticActor;

	//Total wait time, can be changed in the editor
	UPROPERTY(EditAnywhere)
	float TimeToTwitchToMainMenu = 60.0f;

	//Count the amount of seconds passed
	float WaitTimer = 0.f;

	//Keep track of if the sequence is playing or not
	bool isPlaying = false;

	//Referance to game instance
	UMyGameInstance* GameInstance = nullptr;
};
