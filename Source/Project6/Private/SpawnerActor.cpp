// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor.h"

// Sets default values
ASpawnerActor::ASpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	SpawnActors();
}

void ASpawnerActor::SpawnActors()
{
	for (int32 i = 0; i < SpawnLocations.Num(); i++) {
		FVector SpawnLocation = SpawnLocations[i];
		FRotator SpawnRotation = FRotator::ZeroRotator;

		int32 RandomValue = FMath::RandRange(0, 1);

		if (RandomValue == 0) {
			GetWorld()->SpawnActor<AActor>(RotateActorClass, SpawnLocation, SpawnRotation);
		}
		else {
			GetWorld()->SpawnActor<AActor>(MovableActorClass, SpawnLocation, SpawnRotation);
		}


	}
}

