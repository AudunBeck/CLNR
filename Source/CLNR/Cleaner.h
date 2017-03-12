// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CLNRGameModeBase.h"
#include "Cleaner.generated.h"


UCLASS()
class CLNR_API ACleaner : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACleaner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move_X(float AxisValue);
	void Move_Y(float AxisValue);
	void InteractPressed();
	void InteractReleased();

	

protected:
	class ACLNRGameModeBase* CurrentGameMode;

private: 

	bool Interacting = false;
	bool MovingX = false;
	bool MovingY = false;
	
	
};
