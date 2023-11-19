// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trajectory.generated.h"

UCLASS()
class PORTFOLIO_API ATrajectory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrajectory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddTrajectoryPoint();

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<USceneComponent> m_TrajectoryPointClass;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<USceneComponent*> m_Points;
};
