﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

UCLASS()
class PROJECT6_API ASpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<FVector> SpawnLocations;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> MovableActorClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> RotateActorClass;

	void SpawnActors();

};
