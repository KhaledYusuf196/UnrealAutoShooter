// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LevelData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class AUTOSHOOTER_API ULevelData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintGetter=GetHealthLevel)
	int32 HealthLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetSpeedLevel)
	int32 SpeedLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetDamageLevel)
	int32 DamageLevel = 1;
	
	UPROPERTY(EditAnywhere, BlueprintGetter=GetDamageRateLevel)
	int32 DamageRateLevel = 1;

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpgradeDelegate);

	UPROPERTY(BlueprintAssignable)
	FUpgradeDelegate OnUpgrade;

	UFUNCTION(BlueprintGetter)
	int32 GetHealthLevel() const { return HealthLevel; }

	UFUNCTION(BlueprintGetter)
	int32 GetSpeedLevel() const { return SpeedLevel; }

	UFUNCTION(BlueprintGetter)
	int32 GetDamageLevel() const { return DamageLevel; }

	UFUNCTION(BlueprintGetter)
	int32 GetDamageRateLevel() const { return DamageRateLevel; }

	UFUNCTION(BlueprintCallable)
	void UpgradeHealthLevel() { HealthLevel++; OnUpgrade.Broadcast(); }

	UFUNCTION(BlueprintCallable)
	void UpgradeSpeedLevel() { SpeedLevel++; OnUpgrade.Broadcast(); }

	UFUNCTION(BlueprintCallable)
	void UpgradeDamageLevel() { DamageLevel++; OnUpgrade.Broadcast(); }

	UFUNCTION(BlueprintCallable)
	void UpgradeDamageRateLevel() { DamageRateLevel++; OnUpgrade.Broadcast(); }

	UFUNCTION(BlueprintCallable)
	void ResetLevels() { HealthLevel = SpeedLevel = DamageLevel = DamageRateLevel = 1; }
	
};
