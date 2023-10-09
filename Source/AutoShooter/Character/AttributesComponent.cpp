﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"

#include "LevelData.h"


UAttributesComponent::UAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	
}


void UAttributesComponent::UpdateHealth(float DamageAmount)
{
	Health = FMath::Clamp(Health - DamageAmount, 0, MaxHealth);

	if(Health <= 0)
	{
		if(ABaseCharacter* BaseCharacter = GetOwnerCharacter())
		{
			BaseCharacter->OnDeath();
		}
	}
}

void UAttributesComponent::BeginPlay()
{
	Super::BeginPlay();
	

	if(LevelData != nullptr)
	{
		Health = MaxHealth = ATTRIBUTES_DEFAULT_HEALTH + 25 * LevelData->GetHealthLevel();
	
		Speed = ATTRIBUTES_DEFAULT_SPEED + 100 * LevelData->GetSpeedLevel();

		Damage = ATTRIBUTES_DEFAULT_DAMAGE + 25 * LevelData->GetDamageLevel();

		DamageRate = ATTRIBUTES_DEFAULT_DAMAGE_RATE + LevelData->GetDamageRateLevel();
	}
	else
	{
		Health = MaxHealth = ATTRIBUTES_DEFAULT_HEALTH;
	
		Speed = ATTRIBUTES_DEFAULT_SPEED;

		Damage = ATTRIBUTES_DEFAULT_DAMAGE;

		DamageRate = ATTRIBUTES_DEFAULT_DAMAGE_RATE;
	}
	
	
}



