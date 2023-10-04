// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingComponent.h"


// Sets default values for this component's properties
UShootingComponent::UShootingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ShootingCooldown > 0)
	{
		ShootingCooldown = FMath::Max(ShootingCooldown - DeltaTime * ShootingRate, 0);
	}
	
	if(TargetActor == nullptr) return;

	FVector Direction = TargetActor->GetActorLocation() - GetOwner()->GetActorLocation();
	Direction.Z = 0;
	Direction = Direction.GetSafeNormal();
	GetOwner()->SetActorRotation(FRotationMatrix::MakeFromX(Direction).Rotator());

	if(ShootingCooldown > 0) return;
	ShootingCooldown = 1;
	GetWorld()->SpawnActor<AActor>(BulletClass, WeaponMesh->GetSocketTransform(MuzzleSocket));
	
}

