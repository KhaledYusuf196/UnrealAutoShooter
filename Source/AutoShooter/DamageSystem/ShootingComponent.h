// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoShooter/DamageSystem/DamageBaseComponent.h"
#include "ShootingComponent.generated.h"


class ABaseCharacter;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UShootingComponent : public UDamageBaseComponent
{
	GENERATED_BODY()

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	AActor* TargetActor;

	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MuzzleSocket;

private:
	
	void AdjustCharacterDirectionToTarget();
	void Shoot();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> BulletClass;

	float ShootingCooldown = 0;

};
