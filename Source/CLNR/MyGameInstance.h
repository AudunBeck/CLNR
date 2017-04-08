// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CLNR_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	int GameScore = 0;
	
	
	
};