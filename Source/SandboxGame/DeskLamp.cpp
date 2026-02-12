// Fill out your copyright notice in the Description page of Project Settings.


#include "DeskLamp.h"
#include "Components/PointLightComponent.h"
#include "SandboxGameCharacterController.h"

// Sets default values
ADeskLamp::ADeskLamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InitializeDeskLampComponents();
	BuildComponentsHierarchy();
}

// Called when the game starts or when spawned
void ADeskLamp::BeginPlay()
{
	Super::BeginPlay();

	auto playerController = GetWorld()->GetFirstPlayerController();

	if (playerController != nullptr)
	{
		auto characterController = Cast<ASandboxGameCharacterController>(playerController);

		if (characterController != nullptr)
			characterController->SetupDeskLampInput(this);
	}
}

void ADeskLamp::InitializeDeskLampComponents()
{
	DeskLamp = CreateDefaultSubobject<UStaticMeshComponent>("DeskLamp");
	SetSMComponent(DeskLamp, DeskLampMeshPath);

	Toggle = CreateDefaultSubobject<UStaticMeshComponent>("Toggle");
	SetSMComponent(Toggle, ToggleMeshPath);

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	PointLight->SetRelativeLocation(FVector(0.f, 9.f, 35.f));
	PointLight->SetVisibility(false);
}

void ADeskLamp::BuildComponentsHierarchy()
{
	Toggle->SetupAttachment(DeskLamp);
	PointLight->SetupAttachment(DeskLamp);
	RootComponent = DeskLamp;
}

void ADeskLamp::SetSMComponent(UStaticMeshComponent* component, const TCHAR* smPath)
{
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(smPath);

	if (meshAsset.Object != nullptr)
		component->SetStaticMesh(meshAsset.Object);
}

void ADeskLamp::ToggleTheLight()
{
	PointLight->ToggleVisibility();
}

