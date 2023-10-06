// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AttributesComponent.h"
#include "AutoShooter/DamageSystem/DamageBaseComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	AttributesComponent = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	GetAttributes()->UpdateHealth(DamageAmount);
	return DamageAmount;
}

void ABaseCharacter::OnDeath()
{
	GetMovementComponent()->Deactivate();
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
	if(UDamageBaseComponent* DamageComponent = GetDamageComponent())
	{
		DamageComponent->DestroyComponent();
	}
}

UDamageBaseComponent* ABaseCharacter::GetDamageComponent() const
{
	return FindComponentByClass<UDamageBaseComponent>();
}




