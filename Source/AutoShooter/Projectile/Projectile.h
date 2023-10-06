// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
UCLASS()
class AUTOSHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	
	AProjectile();

	
	int32 Damage;

protected:
	
	UFUNCTION()
	void ApplyDamage(const FHitResult& ImpactResult);

	
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;

};
