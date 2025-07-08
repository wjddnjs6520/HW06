// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class PROJECT6_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Scene Component
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	// Static Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComp;

	//회전 로테이터
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Properties")
	FRotator RotateDirection;

	UPROPERTY(EditAnywhere, Category = "RotateActor|Properties")
	float MinRotateSpeed;

	UPROPERTY(EditAnywhere, Category = "RotateActor|Properties")
	float MaxRotateSpeed;

	//움직이는 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Properties")
	float RotateSpeed;

	//숨기기 기능을 위한 bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Hide")
	bool HideFuntion;

	FTimerHandle HideTimerHandle;
	FTimerHandle ShowTimerHandle;

	void HideActor();
	void ShowActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Hide")
	float HideTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Hide")
	float ShowTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
