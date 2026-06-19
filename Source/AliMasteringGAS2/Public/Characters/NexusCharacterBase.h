// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AbilitysystemInterface.h"
#include "NexusCharacterBase.generated.h"

UCLASS()
class ALIMASTERINGGAS2_API ANexusCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ANexusCharacterBase();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nexus|AbilitySystem")
	UAbilitySystemComponent* NexusAbilitySystemComponent;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Nexus|AbilitySystem")
	EGameplayEffectReplicationMode ASCReplicationMode = EGameplayEffectReplicationMode::Mixed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

};
