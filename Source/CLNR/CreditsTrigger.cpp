// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "CreditsTrigger.h"


// Sets default values for this component's properties
UCreditsTrigger::UCreditsTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCreditsTrigger::BeginPlay()
{
	Super::BeginPlay();

	FStringAssetReference SequenceName("/Game/LastLevelSequence.LastLevelSequence");
	ULevelSequence* Asset = Cast<ULevelSequence>(SequenceName.TryLoad());
	FMovieSceneSequencePlaybackSettings Settings;
	SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), Asset, Settings);

	StaticActor->SetActorHiddenInGame(true);

	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
}


// Called every frame
void UCreditsTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AActor* Us = GetOwner();

	if (Us->IsOverlappingActor(Character) && !isPlaying)
	{
		SequencePlayer->Play();
		isPlaying = true;

		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

		PlayerController->GetPawn()->Destroy();
		
		PlayerController->SetViewTarget(CameraActor);

		StaticActor->SetActorHiddenInGame(false);
		GameInstance->ShouldShowHud = false;
	}

	if (isPlaying)
	{
		if (WaitTimer < TimeToTwitchToMainMenu)
		{
			WaitTimer += DeltaTime;
		}
		else {
			UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", false);
		}
	}
}

