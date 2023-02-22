// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyActor.h"
void AMyGameModeBase::BeginPlay() {
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));
	FTransform SpawnLoaction;

	SpawnedActor=GetWorld()->SpawnActor<AMyActor>(AMyActor::StaticClass(), SpawnLoaction);


	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase::DestroyActorFunction, 10);



}



void AMyGameModeBase::DestroyActorFunction() {
	

	if (SpawnedActor != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue,
			TEXT("Actor Destroyed"));
		SpawnedActor->Destroy();
		//actor -> Destroy() 로 없애는듯 
	}

}