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

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	Cast<UShapeComponent>(RootComponent)->bGenerateOverlapEvents = true;
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ACleaner::OnOverlap);
	Cast<UShapeComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &ACleaner::EndOnOverlap);
}

// Called when the game starts or when spawned
void ACleaner::BeginPlay()
{
	Super::BeginPlay();
	CurrentGameMode = GetWorld()->GetAuthGameMode<ACLNRGameModeBase>();
	GetCharacterMovement()->MaxWalkSpeed = Movementspeed;



}

// Called every frame
void ACleaner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Interacting)
	{
		CurrentGameMode->ChangePower(DeltaTime * DrainMultiplier);
	}
	if (MovingX || MovingY)
	{
		CurrentGameMode->ChangePower(DeltaTime);
	}

	if (EndingGame)
	{
		if (TimeAfterEnd <= 0)
		{
			UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
		}
		
		TimeAfterEnd -= DeltaTime;
	}



}

// Called to bind functionality to input
void ACleaner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Interact", IE_Pressed, this, &ACleaner::InteractPressed);
	InputComponent->BindAction("Interact", IE_Released, this, &ACleaner::InteractReleased);
	InputComponent->BindAction("Kit1", IE_Pressed, this, &ACleaner::Kit1);
	InputComponent->BindAction("Kit2", IE_Pressed, this, &ACleaner::Kit2);
	InputComponent->BindAction("Kit3", IE_Pressed, this, &ACleaner::Kit3);
	InputComponent->BindAction("KitInteract", IE_Pressed, this, &ACleaner::SwitchKit);

	InputComponent->BindAxis("Move_X", this, &ACleaner::Move_X);
	InputComponent->BindAxis("Move_Y", this, &ACleaner::Move_Y);


}

void ACleaner::Move_X(float AxisValue)
{


	if ((Controller != NULL) && (AxisValue != 0.0f) && CanMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw + ExtraRotation, 0); //ExtraRotation is added to the player's controls changes, 
		//found this easier than other methods since it just adds a float value, and can be changed into any direction.

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
		MovingX = true;
	}
	else
		MovingX = false;


}
void ACleaner::Move_Y(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f) && CanMove)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw + ExtraRotation, 0);
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
		MovingY = true;
	}
	else
		MovingY = false;

}


void ACleaner::InteractPressed()
{
	Interacting = true;
	GetCharacterMovement()->MaxWalkSpeed = Movementspeed / 2;
}
void ACleaner::InteractReleased()
{
	Interacting = false;
	GetCharacterMovement()->MaxWalkSpeed = Movementspeed;
}

void ACleaner::Kit1()
{
	if (!Interacting && KitNumber != 1)
	{
		KitNumber = 1;
		DrainMultiplier = 2;
		UE_LOG(LogTemp, Warning, TEXT("Kit set to %i"), KitNumber);
		CurrentGameMode->KitMaxValue = Kit1MaxValue;
		CurrentGameMode->KitCurrentValue = 0;
		CurrentGameMode->KitInUse = "Kit1";
	}
}

void ACleaner::Kit2()
{
	if (!Interacting && KitNumber != 2)
	{
		KitNumber = 2;
		DrainMultiplier = 2;
		UE_LOG(LogTemp, Warning, TEXT("Kit set to %i"), KitNumber);
		CurrentGameMode->KitInUse = "Kit2";
	}
}
void ACleaner::Kit3()
{
	if (!Interacting && KitNumber != 3)
	{
		KitNumber = 3;
		DrainMultiplier = 3;
		UE_LOG(LogTemp, Warning, TEXT("Kit set to %i"), KitNumber);
		CurrentGameMode->KitInUse = "Kit3";
	}
}


void ACleaner::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(AKitTest1::StaticClass()))
	{
		KitActor = Cast<AKitTest1>(OtherActor); //Caster AKitTest1 slik at den kan aktiveres når spilleren trykker E, men bare når han står på den.
		OnKitSwitch = true;
	}
	else if (OtherActor->IsA(APowerSwitch::StaticClass()))
	{
		PowerSwitch = Cast<APowerSwitch>(OtherActor); //Kan potensielt legge disse til å komme fra samme class file, slik Gunk, sveising og støv er. (Dette er nedprioritert)
		OnPowerSwitch = true;
	}
}

void ACleaner::EndOnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(AKitTest1::StaticClass()))
	{
		KitActor = nullptr;
		OnKitSwitch = false;
	}
	else if (OtherActor->IsA(APowerSwitch::StaticClass()))
	{
		PowerSwitch = nullptr;
		OnPowerSwitch = false;
	}
}

void ACleaner::SwitchKit()
{
	if (OnKitSwitch)
	{
		KitActor->Activate();
	}

	else if (OnPowerSwitch) //Dette må skrives om til polymorfi.
	{
		PowerSwitch->Activate();
	}
}


