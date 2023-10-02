// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


class ULevelData;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UAttributesComponent();

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
