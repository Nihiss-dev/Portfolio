// Fill out your copyright notice in the Description page of Project Settings.


#include "Trajectory.h"

// Sets default values
ATrajectory::ATrajectory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>("RootComponent");
	SetRootComponent(root);
}

// Called when the game starts or when spawned
void ATrajectory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrajectory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrajectory::AddTrajectoryPoint()
{
	FString componentName = FString::Printf(TEXT("TrajectoryPoint %d"), m_Points.Num());
	USceneComponent* point = NewObject<USceneComponent>(this, m_TrajectoryPointClass, *componentName);
	point->SetupAttachment(GetRootComponent());
	AddInstanceComponent(point);
	AddOwnedComponent(point);
	point->RegisterComponent();
	m_Points.Add(point);
}
