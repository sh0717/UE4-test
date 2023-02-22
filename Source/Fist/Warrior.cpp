// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr) {
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(5);
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FString AWarrior::ToString() {
	return FString::Printf(TEXT("An instance of Warrior %s"), *Name);

}

