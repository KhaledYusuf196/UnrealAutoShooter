// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AttributesComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	AttributesComponent = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));
}


void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


