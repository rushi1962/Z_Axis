// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = true;

	GetCharacterMovement()->AirControl = .2f;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_CameraRotation = 0.f;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_IsZAxisEnabled)
	{
		if (m_CameraRotation <= 10.f)
		{
			AddControllerPitchInput(50.f * DeltaTime);
			m_CameraRotation += 50.f * DeltaTime;
		}
	}
	else
	{
		if (m_CameraRotation >= 0.f)
		{
			AddControllerPitchInput(-50.f * DeltaTime);
			m_CameraRotation -= 50.f * DeltaTime;
		}
		else if(Camera->ProjectionMode == ECameraProjectionMode::Perspective)
		{
			Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
		}
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAction("EnableZAxis",EInputEvent::IE_Pressed, this, &APlayerCharacter::EnableZAxis);
	PlayerInputComponent->BindAction("EnableZAxis", EInputEvent::IE_Released, this, &APlayerCharacter::DisableZAxis);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::EnableZAxis()
{
	Super::EnableZAxis();
	Camera->SetProjectionMode(ECameraProjectionMode::Perspective);

	UZAxisGameInstance* Instance = Cast<UZAxisGameInstance>(GetGameInstance());

	if (Instance)
		Instance->GetZAxisFSM()->ChangeStateTo(EZAxisStateEnum::ZAxisEnabled);
}

void APlayerCharacter::DisableZAxis()
{
	Super::DisableZAxis();

	//Reset player x location
	SetActorLocation(FVector(0.f, GetActorLocation().Y, GetActorLocation().Z)); 
	UZAxisGameInstance* Instance = Cast<UZAxisGameInstance>(GetGameInstance());

	if(Instance)
		Instance->GetZAxisFSM()->ChangeStateTo(EZAxisStateEnum::ZAxisDisabled);
}

void APlayerCharacter::MoveForward(float input)
{
	Super::MoveForward(input);
}

void APlayerCharacter::MoveRight(float input)
{
	Super::MoveRight(input);
}