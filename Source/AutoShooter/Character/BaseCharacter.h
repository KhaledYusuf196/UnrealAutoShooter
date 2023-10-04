// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAttributesComponent;
UCLASS()
class AUTOSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	UFUNCTION(BlueprintGetter)
	UAttributesComponent* GetAttributes() const { return AttributesComponent; }

private:

	UPROPERTY(VisibleAnywhere, BlueprintGetter=GetAttributes)
	UAttributesComponent* AttributesComponent;
	
};
