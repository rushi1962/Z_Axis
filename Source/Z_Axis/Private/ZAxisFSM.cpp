// Fill out your copyright notice in the Description page of Project Settings.

#include "ZAxisGameInstance.h"
#include "ZAxisFSM.h"

// Sets default values
AZAxisFSM::AZAxisFSM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentState = nullptr;
}

// Called when the game starts or when spawned
void AZAxisFSM::BeginPlay()
{
	Super::BeginPlay();
	
	for (AZAxisState* zAxisState : ZAxisStatesArray)
	{
		zAxisState->Init();
	}

	UZAxisGameInstance* Instance = Cast<UZAxisGameInstance>(GetGameInstance());
	Instance->SetZAxisFSM(this);

	ChangeStateTo(EZAxisStateEnum::ZAxisDisabled);
}

// Called every frame
void AZAxisFSM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentState)
	{
		CurrentState->OnTick(DeltaTime);
	}

}

void AZAxisFSM::ChangeStateTo(EZAxisStateEnum newState)
{
	if (CurrentState) CurrentState->OnExit();
	CurrentState = *(ZAxisStatesArray.FindByPredicate([&](AZAxisState* state) {return state->ZAxisStateEnum == newState; }));
	if (CurrentState) CurrentState->OnEnter();
}

