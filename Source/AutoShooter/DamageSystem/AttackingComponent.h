// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageBaseComponent.h"
#include "AttackingComponent.generated.h"

enum EAttackState
{
	EAS_Steady,
	EAS_BuildUp,
	EAS_Hitting,
	EAS_Finishing
};

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UAttackingComponent : public UDamageBaseComponent
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	bool CanHitTarget() const;
	bool IsTargetInRange() const;
	void SetHittingState() { AttackState = EAS_Hitting; }
	void BeginAttack();
	void SetSteadyState() { AttackState = EAS_Steady; }
	void FinishAttack();
	void ApplyDamageToTarget();
	
	EAttackState AttackState;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackBegin);

	UPROPERTY(BlueprintAssignable)
	FAttackBegin AttackBegin;

	FTimerHandle AttackTimerHandle;
};

#define ATTACKING_RANGE 100