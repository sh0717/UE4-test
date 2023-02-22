// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeHandler.h"

// Sets default values
ATimeHandler::ATimeHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TimeScale = 60;
	Hours = 0;
	Minutes = 0;
	ElapsedSeconds = 0;

}

// Called when the game starts or when spawned
void ATimeHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedSeconds += (DeltaTime * TimeScale);
	if (ElapsedSeconds > 60) {
		ElapsedSeconds -= 60;
		Minutes++;

		if (Minutes > 60) {
			Minutes -= 60;
			Hours++;
		}

		OnTimeChanged.Broadcast(Hours, Minutes);
	}

}

