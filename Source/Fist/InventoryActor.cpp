// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"
 
#include "Engine/CollisionProfile.h"



AInventoryActor::AInventoryActor():Super() {

	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr) {

		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}

	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);

}


void AInventoryActor::PickUp() {
	SetActorTickEnabled(false);
	/*what is tick ???
	
	
	*/
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);




}

void AInventoryActor::PutDown(FTransform TargetLocation) {
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
}