// Fill out your copyright notice in the Description page of Project Settings.


#include "RegularEnemy.h"
#include "AIController.h"

// Sets default values
ARegularEnemy::ARegularEnemy() : Target(nullptr)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARegularEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AIController = Cast<AAIController>(GetController());
}

// Called every frame
void ARegularEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GoToTarget();
}

// Called to bind functionality to input
void ARegularEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARegularEnemy::GoToTarget()
{
	AIController->MoveToActor(Target);
}

