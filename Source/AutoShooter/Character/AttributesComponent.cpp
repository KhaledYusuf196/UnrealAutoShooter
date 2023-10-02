﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"

#include "LevelData.h"


UAttributesComponent::UAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	
}



void UAttributesComponent::BeginPlay()
{
	Super::BeginPlay();
	

	if(LevelData != nullptr)
	{
		Health = MaxHealth = 100 + 25 * LevelData->GetHealthLevel();
	
		Speed = 300 + 100 * LevelData->GetSpeedLevel();

		Damage = 100 + 25 * LevelData->GetDamageLevel();

		DamageRate = 1 + LevelData->GetDamageRateLevel();
	}
	else
	{
		Health = MaxHealth = 100;
	
		Speed = 300;

		Damage = 100;

		DamageRate = 1;
	}
	
	
}



