// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


class ABaseCharacter;
class ULevelData;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UAttributesComponent();

	int32 GetDamageRate() const { return DamageRate; }
	
	int32 GetDamage() const { return Damage; }
	
	void UpdateHealth(float DamageAmount);

	ABaseCharacter* GetOwnerCharacter() const { return Cast<ABaseCharacter>(GetOwner()); }


protected:

	virtual void BeginPlay() override;

private:

	
	UPROPERTY(EditAnywhere)
	ULevelData* LevelData;

	int32 MaxHealth;
	int32 Health;
	
	int32 Speed;
	
	int32 Damage;
	
	int32 DamageRate;
	
};

#define ATTRIBUTES_DEFAULT_HEALTH 100

#define ATTRIBUTES_DEFAULT_SPEED 300

#define ATTRIBUTES_DEFAULT_DAMAGE 100

#define ATTRIBUTES_DEFAULT_DAMAGE_RATE 1
