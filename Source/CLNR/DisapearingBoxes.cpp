// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CLNRGameModeBase.h"
#include "DisapearingBoxes.h"


// Sets default values
ADisapearingBoxes::ADisapearingBoxes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}


// Called every frame
void ADisapearingBoxes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints >= WhenToRemove) //If a certain amount of things are cleaned, desroy itself. Only used in the tutorial (blame art).
	{
		Destroy();
	}

}

