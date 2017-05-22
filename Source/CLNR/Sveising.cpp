// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Sveising.h"
#include "Cleaner.h"



ASveising::ASveising()
{
	OurAnimatedComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OurAnimatedComponent"));
	OurAnimatedComponent->SetupAttachment(RootComponent);
	
}

void ASveising::PlayerInteracting(float DeltaTime)
{
	//Kjør animasjon eller partikler
	if (!Done)
	{
		TimeLeft -= DeltaTime;

		if (TimeLeft <= TotalTime / 10)
		{
			PlayerDone();
		}
	}


}

void ASveising::PlayerDone()
{
	if (TargetActor->IsA(APoweredItem::StaticClass()))
	{
		TargetActor->GettingPower = true;
		if (!Done)
		{
			GetWorld()->GetAuthGameMode<ACLNRGameModeBase>()->CurrentPoints += 1;
			Done = true;
			OurParticleComponent->DeactivateSystem();
			int32 NumberOfCables = CableArray.Num(); //When the object is done, change variables in the things this is connected to.
			for (int i = 0; i < NumberOfCables; i++) 
			{
				CableArray[i]->CanBePowered = true;
			}
		}
	}

}

void ASveising::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn)//Also plays an animation, so has to be different than gunk's.
	{
		OverlapPlayer = true;
		OurAnimatedComponent->PlayAnimation(AnimOpen, 0);
		OurAnimatedComponent->SetPosition(0, true);
	}
}

void ASveising::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor->IsA(ACleaner::StaticClass()) && !ConnectedSwitch->SwitchedOn) //Also plays an animation, so has to be different than gunk's.
	{
		OverlapPlayer = false;
		OurAnimatedComponent->PlayAnimation(AnimClosed, 0);
		OurAnimatedComponent->SetPosition(1, true);
	}
}