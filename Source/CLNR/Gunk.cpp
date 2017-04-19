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

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AGunk::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &AGunk::EndOnOverlap);

}

// Called when the game starts or when spawned
void AGunk::BeginPlay()
{
	Super::BeginPlay();
	TimeLeft = TimeLeft*1.1;
	TotalTime = TimeLeft;
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->MaxPoints += 1;
	OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
}

// Called every frame
void AGunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OverlapPlayer == true)
	{
		ACleaner* Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (Player->Interacting == true && Player->KitNumber == Type)
		{
			PlayerInteracting(DeltaTime);
		}
	}


	if (TimeLeft <= TotalTime/10)
	{
		PlayerDone();
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

void AGunk::PlayerInteracting(float DeltaTime)
{
	TimeLeft -= DeltaTime;
	OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
	
}

void AGunk::PlayerDone()
{
	GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
	Destroy();
}

