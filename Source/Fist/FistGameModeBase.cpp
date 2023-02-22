// Copyright Epic Games, Inc. All Rights Reserved.


#include "FistGameModeBase.h"

void AFistGameModeBase::BeginPlay() {
	Super::BeginPlay();
	
	AFistGameModeBase* gm = Cast<AFistGameModeBase>(GetWorld()->GetAuthGameMode());

	if (gm) {
		UUserProfile* nobj = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());

		if (nobj) {
			nobj->ConditionalBeginDestroy();
			nobj = nullptr;
		}
	}
	

}