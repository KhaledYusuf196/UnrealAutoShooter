// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageBaseComponent.h"

#include "AutoShooter/Character/AttributesComponent.h"
#include "AutoShooter/Character/BaseCharacter.h"


// Sets default values for this component's properties
UDamageBaseComponent::UDamageBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;

	// ...
}

void UDamageBaseComponent::InitializeComponent()
{
	Super::InitializeComponent();
	OwnerCharacter = Cast<ABaseCharacter>(GetOwner());
}

int32 UDamageBaseComponent::GetShootingRate() const
{

	if(OwnerCharacter != nullptr)
	{
		return OwnerCharacter->GetAttributes()->GetDamageRate();
	}
	return ATTRIBUTES_DEFAULT_DAMAGE_RATE;
}

int32 UDamageBaseComponent::GetShootingDamage() const
{
	if(OwnerCharacter != nullptr)
	{
		return OwnerCharacter->GetAttributes()->GetDamage();
	}
	return ATTRIBUTES_DEFAULT_DAMAGE;
}
