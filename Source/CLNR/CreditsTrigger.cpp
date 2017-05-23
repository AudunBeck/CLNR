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

	//Load Level Sequence from file
	FStringAssetReference SequenceName("/Game/Meshes/Animations/LastLevelSequence.LastLevelSequence");
	ULevelSequence* Asset = Cast<ULevelSequence>(SequenceName.TryLoad());
	FMovieSceneSequencePlaybackSettings Settings;
	//Create the sequence player instance from asset
	SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), Asset, Settings);

	//Make the character in the sequence invisible when playing
	StaticActor->SetActorHiddenInGame(true);

	//Get a referance to game instance
	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
}


// Called every frame
void UCreditsTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get a referance to the trigger box
	AActor* Us = GetOwner();

	//If player is overlapping and sequence is not playing, start the sequence, destroy the pawn, change camera and set HUD invisible
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

	//If sequence is playing
	if (isPlaying)
	{
		//and the sequence is not complete, add current deltatime to total wait time
		if (WaitTimer < TimeToTwitchToMainMenu)
		{
			WaitTimer += DeltaTime;
		}
		//If the sequence is complete, return to main menu
		else {
			UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", false);
		}
	}
}

