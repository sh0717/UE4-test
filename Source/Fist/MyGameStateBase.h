// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class FIST_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMyGameStateBase();

	UFUNCTION()
	void SetScore(int32 NewScore);

	UFUNCTION()
	int32 GetScore();

private:

	UPROPERTY()
	int32 CurrentScore=0;


	
};



