// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "ImageUtils.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Begin Play : Game Mode Base"));

	if (TestWidget == nullptr)
	{
		TestWidget = CreateWidget<UMyUserWidget>(GetWorld(), MyWidgetBP, "TestName");
		TestWidget->AddToViewport();
		TestWidget->SetVisibility(ESlateVisibility::Visible);

		if (TestWidget)
		{
			UE_LOG(LogTemp, Log, TEXT("Success to load"));
			UTexture2D* texture = nullptr;

			//FString contentPath = FPaths::ProjectContentDir();
			//FString fullContentPath = FPaths::ConvertRelativePathToFull(contentPath);
			//FString fullImagePath = fullContentPath + "TestImage";
			FString fullImagePath = "/Script/Engine.Texture2D'/Game/TestImage.TestImage'";
			UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//if (fullImagePath.Len() > 0)
			//{
			//	fullImagePath.ReplaceInline(TEXT("\\"), TEXT("/"), ESearchCase::CaseSensitive);
			//	UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//	fullImagePath.ReplaceInline(TEXT("//"), TEXT("/"), ESearchCase::CaseSensitive);
			//	UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//	fullImagePath.RemoveFromStart(TEXT("/"));
			//	UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//	fullImagePath.RemoveFromEnd(TEXT("/"));
			//	UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//	FPlatformMisc::NormalizePath(fullImagePath);
			//	UE_LOG(LogTemp, Log, TEXT("%s"), *fullImagePath);
			//}
			//texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *fullImagePath));
			//texture = FImageUtils::ImportFileAsTexture2D(fullImagePath);
			texture = LoadObject<UTexture2D>(NULL, *fullImagePath, NULL, LOAD_None, NULL);
			if (texture)
			{
				auto slot = TestWidget->GetImageSlot();
				if (slot)
				{
					UE_LOG(LogTemp, Log, TEXT("Success to get slot."));
					slot->SetBrushFromTexture(texture);
				}
			}
			else UE_LOG(LogTemp, Log, TEXT("Texture is NULL ptr"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Load failed."));
		}
	}
}
