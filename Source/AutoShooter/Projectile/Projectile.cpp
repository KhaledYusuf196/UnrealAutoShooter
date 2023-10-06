// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collsion"));
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	RootComponent = SphereComponent;
	SphereComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMovementComponent->OnProjectileStop.AddDynamic(this , &AProjectile::ApplyDamage);
}

void AProjectile::ApplyDamage(const FHitResult& ImpactResult)
{
	const FDamageEvent DamageEvent;
	ImpactResult.GetActor()->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);
	Destroy();
}


