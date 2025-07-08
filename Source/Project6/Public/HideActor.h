// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HideActor.generated.h"

UCLASS()
class PROJECT6_API AHideActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHideActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Scene Component
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	// Static Mesh Component
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	FTimerHandle HideTimerHandle;
	FTimerHandle ShowTimerHandle;

	void HideActor();
	void ShowActor();
};
