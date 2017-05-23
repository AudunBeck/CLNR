// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "BackgroundShip.h"


// Sets default values
ABackgroundShip::ABackgroundShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}


// Called every frame
void ABackgroundShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator CurrentRotation = GetActorRotation();
	FRotator AddedRotation;
	AddedRotation = (Direction * DeltaTime) * RotationSpeed;
	SetActorRotation(CurrentRotation + AddedRotation);
}

