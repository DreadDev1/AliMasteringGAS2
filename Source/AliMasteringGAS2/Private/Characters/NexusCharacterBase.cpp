// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NexusCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ANexusCharacterBase::ANexusCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
#pragma region AbilitySystemComponent
	NexusAbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("NexusAbilitySystemComponent"));
	NexusAbilitySystemComponent->SetIsReplicated(true);
	NexusAbilitySystemComponent->SetReplicationMode(ASCReplicationMode);
#pragma endregion AbilitySystemComponent

	GetCapsuleComponent()->InitCapsuleSize(35.f, 90.f);
	
#pragma region CharacterMovement Settings
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 2000.f;
#pragma endregion CharacterMovement Settings
	
}


void ANexusCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ANexusCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANexusCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ANexusCharacterBase::GetAbilitySystemComponent() const
{
	return NexusAbilitySystemComponent;
}

void ANexusCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (NexusAbilitySystemComponent) { NexusAbilitySystemComponent->InitAbilityActorInfo(this, this); }
}

void ANexusCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (NexusAbilitySystemComponent) { NexusAbilitySystemComponent->InitAbilityActorInfo(this, this); }
}

