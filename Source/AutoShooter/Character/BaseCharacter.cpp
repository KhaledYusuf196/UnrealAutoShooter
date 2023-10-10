// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AttributesComponent.h"
#include "AutoShooter/DamageSystem/DamageBaseComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"


ABaseCharacter::ABaseCharacter()
{
	AttributesComponent = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	DefaultMeshTransform = GetMesh()->GetRelativeTransform();
}

void ABaseCharacter::Respawn()
{
	GetAttributes()->ResetHealth();
	GetMesh()->SetSimulatePhysics(false);
	GetMesh()->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	ResetMeshTransform();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCharacterMovement()->SetDefaultMovementMode();
	if(UDamageBaseComponent* DamageComponent = GetDamageComponent())
	{
		DamageComponent->SetComponentTickEnabled(true);
	}
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                                 AActor* DamageCauser)
{
	GetAttributes()->UpdateHealth(DamageAmount);
	return DamageAmount;
}

void ABaseCharacter::OnDeath()
{
	GetCharacterMovement()->DisableMovement();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
	if(UDamageBaseComponent* DamageComponent = GetDamageComponent())
	{
		DamageComponent->SetComponentTickEnabled(false);
	}
	DeathDelegate.Broadcast(this);
}

UDamageBaseComponent* ABaseCharacter::GetDamageComponent() const
{
	return FindComponentByClass<UDamageBaseComponent>();
}

void ABaseCharacter::ResetMeshTransform()
{
	GetMesh()->SetRelativeTransform(DefaultMeshTransform);
}




