// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoShooter/Character/BaseCharacter.h"
#include "Components/ActorComponent.h"
#include "DamageBaseComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UDamageBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDamageBaseComponent();

	virtual void InitializeComponent() override;

protected:

	int32 GetShootingRate() const;
	int32 GetShootingDamage() const;

	UPROPERTY()
	ABaseCharacter* OwnerCharacter;
};
