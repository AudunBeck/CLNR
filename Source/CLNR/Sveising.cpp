// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Sveising.h"
#include "GunkSpawner.h"
#include "Cleaner.h"



ASveising::ASveising()
{
	OurAnimatedComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurAnimatedComponent"));
	OurAnimatedComponent->SetupAttachment(RootComponent);
}
 
void ASveising::PlayerInteracting(float DeltaTime)
{
	//Kjør animasjon eller partikler
	if (!TargetActor->TurnedOn && TargetActor != nullptr && !Done)
	{
		TimeLeft -= DeltaTime;
		OurVisibleComponent->SetWorldScale3D(FVector(TimeLeft / TotalTime, TimeLeft / TotalTime, TimeLeft / TotalTime));
	}
	
}

void ASveising::PlayerDone()
{
	if (TargetActor->IsA(AGunkSpawner::StaticClass()) && TargetActor != nullptr)
	{
		TargetActor->GettingPower = true;
		if (!Done)
		{
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
			Done = true;
		}
		
		
	}

	else if (TargetActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no target actor on Sveising %i"), 0);
	}
}

void ASveising::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (ConnectedSwitch == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no target actor on Sveising, for Switch!%i"), 0);
	}
	else if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn)
	{
		OverlapPlayer = true;
		OurAnimatedComponent->PlayAnimation(AnimOpen, 0);
		OurAnimatedComponent->SetPosition(0, true);
	}
}

void ASveising::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (ConnectedSwitch == nullptr || TargetActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing ConnectedSwitch or TargetActor%i"), 0);
	}

	else if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn)
	{
		OverlapPlayer = false;
		OurAnimatedComponent->PlayAnimation(AnimClosed, 0);
		OurAnimatedComponent->SetPosition(1, true);
	}

}