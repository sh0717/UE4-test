// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barrack.generated.h"

UCLASS()
class FIST_API ABarrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UStaticMeshComponent* BuildingMesh;
	UPROPERTY()
		UParticleSystemComponent* SpawnPoint;

	UPROPERTY()
		UClass* UnitToSpawn;

	UPROPERTY()
		float SpawnInterval;
	UFUNCTION()
		void SpawnUnit();

	UPROPERTY()
		FTimerHandle SpawnTimerHandle;
};
