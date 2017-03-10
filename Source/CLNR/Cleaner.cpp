// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "Cleaner.h"


// Sets default values
ACleaner::ACleaner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
}

// Called when the game starts or when spawned
void ACleaner::BeginPlay()
{
	Super::BeginPlay();
	CurrentGameMode = GetWorld()->GetAuthGameMode<ACLNRGameModeBase>();
	UE_LOG(LogTemp, Warning, TEXT("Power is set to %f"), CurrentGameMode->CurrentPower);
	CurrentGameMode->CurrentPower = CurrentGameMode->MaxPower;
	UE_LOG(LogTemp, Warning, TEXT("Power is set to %f"), CurrentGameMode->CurrentPower);

}

// Called every frame
void ACleaner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Interacting)
	{
		CurrentGameMode->ChangePower(DeltaTime * 10);
		UE_LOG(LogTemp, Warning, TEXT("Power is set to %f"), CurrentGameMode->CurrentPower);
	}

	
		
}

// Called to bind functionality to input
void ACleaner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Interact", IE_Pressed, this, &ACleaner::InteractPressed);
	InputComponent->BindAction("Interact", IE_Released, this, &ACleaner::InteractReleased);

	InputComponent->BindAxis("Move_X", this, &ACleaner::Move_X);
	InputComponent->BindAxis("Move_Y", this, &ACleaner::Move_Y);

}

void ACleaner::Move_X(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
 	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}

}
void ACleaner::Move_Y(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
	}

}
void ACleaner::InteractPressed() 
{
	Interacting = true;
}
void ACleaner::InteractReleased()
{
	Interacting = false;
}

