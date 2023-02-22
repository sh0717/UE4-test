// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingMovementComponent.h"

// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	RotationSpeed = 5.0f;
	OrbitDistance = 100.0f;
	CurrentValue = 0.0f;
	RotateToFaceOutwards = true;
	// ...
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	float CurrentValueInRadians = FMath::DegreesToRadians<float>(CurrentValue);

	SetRelativeLocation(FVector(OrbitDistance * FMath::Cos(CurrentValueInRadians),
		OrbitDistance * FMath::Sin(CurrentValueInRadians),
		GetRelativeLocation().Z));
	
	/* setrelativelocation (변화할 벡터량)*/


	// ...\


	/*현재 위치 변경 시켜주기 */
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed * DeltaTime), 360);
}

