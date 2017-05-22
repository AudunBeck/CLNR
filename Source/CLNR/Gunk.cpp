// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Gunk.h"
#include "Cleaner.h"
#include "CLNRGameModeBase.h"


// Sets default values
AGunk::AGunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AGunk::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &AGunk::EndOnOverlap);

	OurParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleComponent"));
	OurParticleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGunk::BeginPlay()
{
	Super::BeginPlay();
	TimeLeft = TimeLeft*1.1; // Gives the mesh 10% more time, this is to make it Destroy() when its sized 10%.
	TotalTime = TimeLeft;
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->MaxPoints += 1; //Adds a point that needs to be taken, done here so that each gunk adds one point.
	OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
}

// Called every frame
void AGunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OverlapPlayer == true)
	{
		ACleaner* Player = nullptr;
		if (Player == nullptr)
			Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (Player->Interacting == true && Player->KitNumber == Type) //If the player interacts with the right kit
		{
			PlayerInteracting(DeltaTime);
		}
	}


	
	
}

void AGunk::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		OverlapPlayer = true;
	}
}

void AGunk::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		OverlapPlayer = false;
	}

}

void AGunk::PlayerInteracting(float DeltaTime) //When the player is interacting with the Gunk, remove time from timeleft, and shrink.
{
	TimeLeft -= DeltaTime;
	OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));

	if (TimeLeft <= TotalTime / 10)
	{
		PlayerDone();
	}
	
}

void AGunk::PlayerDone() // Add a point to current points, and destroy itself.
{
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
	Destroy();
}

