// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "MyTriggerVolume.h"
#include "TriggerVolEventListener.generated.h"

UCLASS()
class FIST_API ATriggerVolEventListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerVolEventListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY()
		UPointLightComponent* PointLight;
	UPROPERTY(EditAnywhere)
		AMyTriggerVolume* TriggerEventSource;
	UFUNCTION()
		void OnTriggerEvent();

};
