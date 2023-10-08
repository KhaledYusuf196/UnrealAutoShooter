// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackingComponent.h"

void UAttackingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CanHitTarget())
	{
		BeginAttack();
	}
	else if(AttackState == EAS_Hitting)
	{
		if(IsTargetInRange()) ApplyDamageToTarget();
		FinishAttack();
	}
}

void UAttackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	OwnerCharacter->GetWorldTimerManager().ClearTimer(AttackTimerHandle);
}

bool UAttackingComponent::CanHitTarget() const
{
	return AttackState == EAS_Steady && IsTargetInRange();
}

bool UAttackingComponent::IsTargetInRange() const
{
	if(TargetActor == nullptr) return false;
	
	const float DistanceSquared = (TargetActor->GetActorLocation() - GetOwner()->GetActorLocation()).SizeSquared();

	return DistanceSquared <= ATTACKING_RANGE * ATTACKING_RANGE;
}

void UAttackingComponent::BeginAttack()
{
	AttackState = EAS_BuildUp;
	OwnerCharacter->GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &UAttackingComponent::SetHittingState, GetShootingRate());
	AttackBegin.Broadcast();
}

void UAttackingComponent::FinishAttack()
{
	AttackState = EAS_Finishing;
	OwnerCharacter->GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &UAttackingComponent::SetSteadyState, GetShootingRate());
}

void UAttackingComponent::ApplyDamageToTarget()
{
	const FDamageEvent DamageEvent;
	TargetActor->TakeDamage(GetShootingDamage(), DamageEvent, GetOwner()->GetInstigatorController(), nullptr);
}
