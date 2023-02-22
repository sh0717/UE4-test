// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Profile.generated.h"

UCLASS(Blueprintable, BlueprintType)
class FIST_API AProfile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProfile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float HpMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		FString name;



};
