// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CameraRotator.h"


// Sets default values
ACameraRotator::ACameraRotator()
{
	PrimaryActorTick.bCanEverTick = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ACameraRotator::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &ACameraRotator::EndOnOverlap);

}

void ACameraRotator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Player)
	{
		if (Player->EndingLevel)
			Destroy();

		if (Rotating == true)
		{
			if (Inside)//If the player is inside the rotating area, starts rotating the spring arm (with the camera) to the rotation set in the editor.
			{
				if (Player->SpringArm->RelativeRotation.Yaw <= WhereToRotate)
				{
					Player->SpringArm->RelativeRotation.Yaw += DeltaTime * CameraRotationSpeed;
				}
				else if (Player->SpringArm->RelativeRotation.Yaw >= WhereToRotate)
				{
					Player->SpringArm->RelativeRotation.Yaw = WhereToRotate;
					Rotating = false;
				}
			}

			else if (!Inside) //If the players leaves the area, resets it back to 0, at the same speed as the other.
			{
				if (Player->SpringArm->RelativeRotation.Yaw >= WhereToRotate)
				{
					Player->SpringArm->RelativeRotation.Yaw -= DeltaTime * CameraRotationSpeed;
				}
				else if (Player->SpringArm->RelativeRotation.Yaw <= WhereToRotate)
				{
					Player->SpringArm->RelativeRotation.Yaw = WhereToRotate;
					Rotating = false;
				}
			}

		}

	}
}

void ACameraRotator::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		Rotating = true;
		Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());
		WhereToRotate = Rotation;
		Player->ExtraRotation = Rotation;
		Inside = true;

	}
}

void ACameraRotator::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(ACleaner::StaticClass()))
	{
		Rotating = true;
		Player = Cast<ACleaner>(GetWorld()->GetFirstPlayerController()->GetPawn());
		WhereToRotate = 0;
		Player->ExtraRotation = 0.f;
		Inside = false;
	}
}


