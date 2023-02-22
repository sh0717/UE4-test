// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameModeBase.h"
// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200.f, 200.f, 100.f));
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr) {
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

	Mesh->AttachToComponent(TriggerZone, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);


	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.ExecuteIfBound();
			auto Color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParameterDelegate.ExecuteIfBound(Color);

			MyGameMode->MyMulticastDelegate.Broadcast();

		}

	}

	/*event 의 브로드캐스트 실행*/
	OnPlayerEntered.Broadcast();
	return;
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s left me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	return;
}