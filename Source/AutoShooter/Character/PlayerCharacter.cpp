// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "LevelUpSystem.h"


APlayerCharacter::APlayerCharacter()
{
	ShootingComponent = CreateDefaultSubobject<UShootingComponent>(TEXT("Shooting Component"));
	LevelUpSystem = CreateDefaultSubobject<ULevelUpSystem>(TEXT("Character Level"));

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("weapon_Socket"));
}

void APlayerCharacter::OnConstruction(const FTransform& Transform)
{
	if(ShootingComponent) ShootingComponent->WeaponMesh = WeaponMesh;
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(ShootingComponent) ShootingComponent->TargetActor = GetNearbyTarget();
}



AActor* APlayerCharacter::GetNearbyTarget() const
{
	AActor* NearestActor = nullptr;
	float NearestSquaredDistance = DetectionRange * DetectionRange;
	if(TArray<FOverlapResult> NearbyOverlaps;
		GetWorld()->OverlapMultiByChannel(NearbyOverlaps, GetActorLocation(), FQuat::Identity, TargetTraceChannel, FCollisionShape::MakeSphere(DetectionRange)))
	{
		for (auto NearbyOverlap : NearbyOverlaps)
		{
			AActor* CurrentActor = NearbyOverlap.GetActor();
			FVector ActorLocation = CurrentActor->GetActorLocation();
			if(FHitResult HitResult; GetWorld()->LineTraceSingleByChannel(HitResult, GetActorLocation(), ActorLocation, ECollisionChannel::ECC_Visibility))
			{
				if(HitResult.GetActor() == CurrentActor && NearestSquaredDistance > (ActorLocation - GetActorLocation()).SizeSquared())
				{
					NearestActor = CurrentActor;
					NearestSquaredDistance = (ActorLocation - GetActorLocation()).SizeSquared();
				}
			}
		}
	}
	
	return NearestActor;
}
