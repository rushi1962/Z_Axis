// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCharacter.h"
#include "DeathBox.h"

// Sets default values
ADeathBox::ADeathBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	SetRootComponent(Collider);

	Collider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collider->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void ADeathBox::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ADeathBox::OnOverlapBegin);	
}

void ADeathBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGameCharacter* otherCharacter = Cast<AGameCharacter>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("Begin overlap GameCharacter"));
	if (otherCharacter)
	{
		otherCharacter->KillCharacter();
	}
}

