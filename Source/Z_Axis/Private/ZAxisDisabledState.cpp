// Fill out your copyright notice in the Description page of Project Settings.

#include "ZAxisFSM.h"
#include "BoxPlatform.h"
#include "ZAxisGameInstance.h"
#include "ZAxisDisabledState.h"

AZAxisDisabledState::AZAxisDisabledState()
{

}

void AZAxisDisabledState::Init()
{
	Super::Init();
	ZAxisStateEnum = EZAxisStateEnum::ZAxisDisabled;
	UE_LOG(LogTemp, Warning, TEXT("ZAxisDisabledState Init"));
}

void AZAxisDisabledState::OnEnter()
{
	Super::OnEnter();
	UE_LOG(LogTemp, Warning, TEXT("ZAxisDisabledState OnEnter"));

	UZAxisGameInstance* Instance = Cast<UZAxisGameInstance>(GetGameInstance());

	if (Instance)
		for (ABoxPlatform* box : Instance->GetZAxisFSM()->BoxPlatformArray)
		{
			box->SetZAxisEnabled(false);
		}
}

void AZAxisDisabledState::OnExit()
{
	Super::OnExit();
	UE_LOG(LogTemp, Warning, TEXT("ZAxisDisabledState OnExit"));
}

void AZAxisDisabledState::OnTick(float DeltaTime)
{
	Super::OnTick(DeltaTime);
}