// Fill out your copyright notice in the Description page of Project Settings.

#include "CLNR.h"
#include "PoweredItem.h"


// Sets default values
APoweredItem::APoweredItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoweredItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoweredItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APoweredItem::PowerOn()//A base for all the items that can be powered by a switch. (Spawners and doors)
{

}

