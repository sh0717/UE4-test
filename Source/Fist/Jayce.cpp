// Fill out your copyright notice in the Description page of Project Settings.


#include "Jayce.h"

// Sets default values
AJayce::AJayce()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJayce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJayce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJayce::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AJayce::Forward);
	PlayerInputComponent->BindAxis("Right", this, &AJayce::Right);
	PlayerInputComponent->BindAxis("Yaw", this, &AJayce::Yaw);
}


void AJayce::Forward(float amount) {
	AddMovementInput(GetActorForwardVector(), amount);
}
void AJayce::Right(float amount) {
	AddMovementInput(GetActorRightVector(), amount);
}
void AJayce::Yaw(float amount) {
	AddControllerYawInput(amount);
}