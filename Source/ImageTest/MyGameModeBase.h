// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyUserWidget.h"
#include "GameFramework/GameModeBase.h"

#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class IMAGETEST_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<UMyUserWidget> MyWidgetBP;

	UPROPERTY(EditAnywhere, Category = "Widget")
		class UMyUserWidget* TestWidget;
};
