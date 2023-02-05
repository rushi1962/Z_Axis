// Fill out your copyright notice in the Description page of Project Settings.


#include "ZAxisFSM.h"
#include "BoxPlatform.h"
#include "ZAxisGameInstance.h"
#include "GameCharacter.h"
#include "ZAxisEnabledState.h"

AZAxisEnabledState::AZAxisEnabledState()
{

}

void AZAxisEnabledState::Init()
{
	Super::Init();
	ZAxisStateEnum = EZAxisStateEnum::ZAxisEnabled;
	UE_LOG(LogTemp, Warning, TEXT("ZAxisEnabled Init"));
}

void AZAxisEnabledState::OnEnter()
{
	Super::OnEnter();
	UE_LOG(LogTemp, Warning, TEXT("ZAxisEnabled OnEnter"));

	UZAxisGameInstance* Instance = Cast<UZAxisGameInstance>(GetGameInstance());

	if (Instance)
		for (ABoxPlatform* box : Instance->GetZAxisFSM()->BoxPlatformArray)
		{
			box->SetZAxisEnabled(true);
		}

	if (Instance)
		for (AGameCharacter* character : Instance->GetZAxisFSM()->GameCharacterArray)
		{
			character->EnableZAxis();
		}
}

void AZAxisEnabledState::OnExit()
{
	Super::OnExit();
	UE_LOG(LogTemp, Warning, TEXT("ZAxisEnabled OnExit"));
}

void AZAxisEnabledState::OnTick(float DeltaTime)
{
	Super::OnTick(DeltaTime);
}