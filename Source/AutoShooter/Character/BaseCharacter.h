// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UDamageBaseComponent;
class UAttributesComponent;
UCLASS()
class AUTOSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	UFUNCTION(BlueprintGetter)
	UAttributesComponent* GetAttributes() const { return AttributesComponent; }

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	 virtual void OnDeath();

	virtual UDamageBaseComponent* GetDamageComponent() const;

private:

	UPROPERTY(VisibleAnywhere, BlueprintGetter=GetAttributes)
	UAttributesComponent* AttributesComponent;

	
	
};
