#pragma once



#include "UObject/ObjectMacros.h "
#include "ColoredTexture.generated.h"



USTRUCT(Blueprintable)

struct FIST_API FColoredTexture {

	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category =UHD)
	UTexture* Texture;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UHD)
	FLinearColor Color;
};