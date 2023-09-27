// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "TestWC.generated.h"

/**
 * 
 */
UCLASS()
class IMAGETEST_API UTestWC : public UWidgetComponent
{
	GENERATED_BODY()
	
public:

private:

	UPROPERTY()
	UUserWidget* widgetBlueprint;

};
