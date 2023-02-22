// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"




/**
 * 
 */
#include "UserProfile.generated.h"

UENUM()
enum Status
{
	Stopped     UMETA(DisplayName = "Stopped"),
	Moving      UMETA(DisplayName = "Moving"),
	Attacking   UMETA(DisplayName = "Attacking"),
};




UCLASS(Blueprintable,BlueprintType)
class FIST_API UUserProfile : public UObject
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Stats)
	float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString name;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer ;

	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
		FStringClassReference UClassGameMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FColoredTexture Texture; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		TEnumAsByte<Status> status;

};
