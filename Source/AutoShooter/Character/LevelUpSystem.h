// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelUpSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AUTOSHOOTER_API ULevelUpSystem : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintPure)
	float GetCurrentLevel() const { return powf(ExperiencePoints / BaseLevelPoints, 1 / LevelPointsExponent ); }

	UFUNCTION(BlueprintPure)
	int32 GetCurrentLevelINT32() const { return GetCurrentLevel(); }

	UFUNCTION(BlueprintPure)
	float GetLevelPercent() const { return GetCurrentLevel() - FMath::Floor(GetCurrentLevel()); }

	UFUNCTION(BlueprintPure)
	bool CanUpgrade() const { return ConsumedLevels < GetCurrentLevelINT32(); }

	UPROPERTY(BlueprintReadWrite)
	float ExperiencePoints;

	UPROPERTY(BlueprintReadWrite)
	int32 ConsumedLevels;

private:

	UPROPERTY(EditAnywhere)
	float BaseLevelPoints = 100;

	UPROPERTY(EditAnywhere)
	float LevelPointsExponent = 1;

	

		
};
