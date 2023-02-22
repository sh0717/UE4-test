// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyActor.h"
#include "MyGameModeBase.generated.h"


DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature,FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)
/*delegate 선언해주기?*/
/**
 * 
 */
UCLASS()
class FIST_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;


	UPROPERTY()
	AMyActor* SpawnedActor;

	UFUNCTION()
	void DestroyActorFunction();

	
	FStandardDelegateSignature MyStandardDelegate;
	FParamDelegateSignature MyParameterDelegate;
	FMulticastDelegateSignature MyMulticastDelegate;
};
