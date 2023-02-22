// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AInventoryCharacter::AInventoryCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* sub object 생성하기*/

	MyInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");

}

// Called when the game starts or when spawned
void AInventoryCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementInput.IsZero()) {
		MovementInput *= 100;

		FVector InputVector = FVector(0, 0, 0);
		InputVector += GetActorForwardVector() * MovementInput.X * DeltaTime;
		InputVector += GetActorRightVector() * MovementInput.Y * DeltaTime;
		GetCharacterMovement()->AddInputVector(InputVector);

	}

	if (!CameraInput.IsNearlyZero()) {
		FRotator NewRotation = GetActorRotation();
		NewRotation.Pitch += CameraInput.Y;
		NewRotation.Yaw += CameraInput.X;

		APlayerController* MyPlayerController = Cast<APlayerController>(GetController());

		if (MyPlayerController != nullptr)
		{
			MyPlayerController->AddYawInput(CameraInput.X);
			MyPlayerController->AddPitchInput(CameraInput.Y);
		}
		SetActorRotation(NewRotation);


	}

}

// Called to bind functionality to input
void AInventoryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAction("DropItem", EInputEvent::IE_Pressed, this, &AInventoryCharacter::DropItem);
	
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AInventoryCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AInventoryCharacter::MoveRight);
	PlayerInputComponent->BindAxis("CameraPitch", this, &AInventoryCharacter::PitchCamera);
	PlayerInputComponent->BindAxis("CameraYaw", this, &AInventoryCharacter::YawCamera);
}




void AInventoryCharacter::MoveForward(float AxisValue) {
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::MoveRight(float AxisValue) {
	MovementInput.Y= FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::PitchCamera(float AxisValue)
{
	CameraInput.Y = -AxisValue;
}

void AInventoryCharacter::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}


void AInventoryCharacter::DropItem() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("trash"));
	if (MyInventory->CurrentInventory.Num() == 0) {
		/* firstly check 
			inventory 컴포넌트의 TARRAY 의 size 체크
		*/
		return;
	}

	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);

	FVector ItemOrigin;
	FVector ItemBounds;

	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);


}


void AInventoryCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}

}

void AInventoryCharacter::TakeItem(AInventoryActor* InventoryItem) {
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("item get"));


	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);

}