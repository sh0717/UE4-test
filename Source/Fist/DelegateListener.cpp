// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
	PointLight->SetLightColor(FLinearColor::Blue);


}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {
	
	
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
		AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
			MyGameMode->MyParameterDelegate.BindUObject(this, &ADelegateListener::SetLightColor);
		
		}
	}

	
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ADelegateListener::EnableLight() {

	
	PointLight->SetVisibility(true);
}

void ADelegateListener::SetLightColor(FLinearColor LightColor) {
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("sex Ssex sex king"));
	PointLight->SetLightColor(LightColor);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(GameMode);
		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.Unbind();

		}

	}

}