// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "GunkSpawner.h"
#include "Gunk.h"
#include "Cleaner.h"

// Sets default values
AGunkSpawner::AGunkSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	OurAnimatedComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurAnimatedComponent"));
	OurAnimatedComponent->SetupAttachment(RootComponent);

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AGunkSpawner::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &AGunkSpawner::EndOnOverlap);

}

void AGunkSpawner::BeginPlay()
{
	Super::BeginPlay();
	if (ContainGunk)
	{
		OurAnimatedComponent->SetMaterial(4, Filled);
		GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->MaxPoints += 1;
	}

		
}

void AGunkSpawner::Tick(float DeltaTime) // Functions mostly as Gunk does, but alot not needed from there, can go back later to check if it can be connected to it.
{
	Super::Tick(DeltaTime);

	if (OverlapPlayer == true)
	{
		ACleaner* Player = nullptr;
		if (Player == nullptr)
			Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (Player->Interacting == true && Player->KitNumber == 1 && ContainGunk)
		{
			OurAnimatedComponent->SetMaterial(4, Empty);
			ContainGunk = false;
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
		}
	}


}


void AGunkSpawner::PowerOn()
{
	UWorld* World = GetWorld();

	if (GettingPower && TurnedOn)
	{
		if (ContainGunk)// If the spawner contains gunk when its activated, it will spawn the amount of gunk its set to have inside it.
		{ 
			for (int i = 0; i < GunkAmount; i++)
			{
				FVector SpawnLocation = GetActorLocation() + FVector(FMath::FRandRange(RandomRangeBot, RandomRangeTop), FMath::FRandRange(RandomRangeBot, RandomRangeTop), DistanceToFloor);
				AGunk *tempGunk = World->SpawnActor<AGunk>(GunkBlueprint, SpawnLocation, FRotator::ZeroRotator);				
			}
			ContainGunk = false;
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
			
			OurAnimatedComponent->SetMaterial(4, Empty);
		}

		else
		{
			
		}
		OurAnimatedComponent->PlayAnimation(AnimOpen, 1); //Plays its animation if the power is turned on.
	}

	else
	{
		OurAnimatedComponent->PlayAnimation(AnimOpen, 0); //Plays it once more then stops the looping.
	}
}

void AGunkSpawner::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	
	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		OverlapPlayer = true;
		UE_LOG(LogTemp, Warning, TEXT("Touching player %i"), 0);
	}
}

void AGunkSpawner::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		OverlapPlayer = false;
	}

}