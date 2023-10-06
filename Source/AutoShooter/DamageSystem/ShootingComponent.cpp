// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingComponent.h"

#include "AutoShooter/Projectile/Projectile.h"




// Called every frame
void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ShootingCooldown > 0)
	{
		ShootingCooldown = FMath::Max(ShootingCooldown - DeltaTime * GetShootingRate(), 0);
	}
	
	if(TargetActor == nullptr) return;

	AdjustCharacterDirectionToTarget();

	if(ShootingCooldown > 0) return;
	Shoot();
	
}

void UShootingComponent::AdjustCharacterDirectionToTarget()
{
	FVector Direction = TargetActor->GetActorLocation() - GetOwner()->GetActorLocation();
	Direction.Z = 0;
	Direction = Direction.GetSafeNormal();
	GetOwner()->SetActorRotation(FRotationMatrix::MakeFromX(Direction).Rotator());
}

void UShootingComponent::Shoot()
{
	ShootingCooldown = 1;
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(BulletClass, WeaponMesh->GetSocketTransform(MuzzleSocket));
	Projectile->Damage = GetShootingDamage();
	Projectile->SetInstigator(OwnerCharacter);
}

