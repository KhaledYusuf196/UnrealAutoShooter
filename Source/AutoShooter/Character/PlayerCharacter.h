// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "AutoShooter/DamageSystem/ShootingComponent.h"

#include "PlayerCharacter.generated.h"

class ULevelUpSystem;
class UShootingComponent;
/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual UDamageBaseComponent* GetDamageComponent() const override { return ShootingComponent; }

private:
	
	AActor* GetNearbyTarget() const;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ECollisionChannel> TargetTraceChannel;

	UPROPERTY(VisibleAnywhere)
	UShootingComponent* ShootingComponent;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere)
	ULevelUpSystem* LevelUpSystem;

	UPROPERTY(EditAnywhere)
	float DetectionRange = 1000;
};
