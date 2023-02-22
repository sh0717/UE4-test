// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent.h"

// Sets default values for this component's properties
URandomMovementComponent::URandomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MovementRadius = 5.0f;
	// ...
}


// Called when the game starts
void URandomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URandomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	/*오우너를 얻어내서 오우너의 location 을 change 한다 ? 
	Randommovement actor 가 애는 어떻게 가질 수 있을까 ?

	actor component 를 


	*/
	AActor* Parent = GetOwner();

	if (Parent) {
		auto NewPos = Parent->GetActorLocation() + FVector(FMath::FRandRange(-1, 1) * MovementRadius,
			FMath::FRandRange(-1, 1) * MovementRadius,
			FMath::FRandRange(-1, 1) * MovementRadius);
	
		Parent->SetActorLocation(NewPos);
	}
	// ...
}

