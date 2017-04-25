// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "PowerSwitch.h"



// Sets default values
APowerSwitch::APowerSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	OurVisibleComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APowerSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerSwitch::Activate() // Må skrives om til Polymorfi for KitTest1 og PowerSwitch
{
	UE_LOG(LogTemp, Warning, TEXT("Using PowerSwitch %i"), 0);

	if (SwitchedOn)
	{
		OurVisibleComponent->PlayAnimation(AnimOn, 0);
		SwitchedOn = false;
		OurVisibleComponent->SetPosition(0, true);
	}
		
	else if (!SwitchedOn)
	{
		OurVisibleComponent->PlayAnimation(AnimOff, 0);
		SwitchedOn = true;
		OurVisibleComponent->SetPosition(1, true);

		if (TargetActor->IsA(AGunkSpawner::StaticClass()) && TargetActor != nullptr)
		{
			TargetActor->TurnedOn = !TargetActor->TurnedOn;
			TargetActor->PowerOn();
		}
	}
		
	
}

