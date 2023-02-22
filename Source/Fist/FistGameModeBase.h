// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "UserProfile.h"

/*this should be the last include */
#include "FistGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FIST_API AFistGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	void BeginPlay();




public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UClassNames)
	TSubclassOf<UUserProfile> UPBlueprintClassName;
};
