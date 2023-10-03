// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UShootingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UShootingComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

protected:
	
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite)
	int32 ShootingRate = 1;

	UPROPERTY(BlueprintReadWrite)
	AActor* TargetActor;

	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MuzzleSocket;

private:

	
	

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> BulletClass;

	float ShootingCooldown = 0;

};
