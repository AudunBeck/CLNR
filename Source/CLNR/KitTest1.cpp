// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "KitTest1.h"
#include "Cleaner.h"
#include "CLNRGameModeBase.h"


// Sets default values
AKitTest1::AKitTest1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AKitTest1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKitTest1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKitTest1::Activate()
{
	ACleaner* Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	if (KitChange == 1)
		Player->Kit1();

	else if (KitChange == 2)
		Player->Kit2();

	else if (KitChange == 3)
		Player->Kit3();

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR: Kit set to %i, this does not exist."), KitChange);
	}
}