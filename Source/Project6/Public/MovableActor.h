// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableActor.generated.h"

UCLASS()
class PROJECT6_API AMovableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Scene Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor|Components")
	USceneComponent* SceneRoot;
	// Static Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Components")

	UStaticMeshComponent* StaticMeshComp;

	//액터 처음 위치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Properties")
	FVector StartLocation;

	//움직이는 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoveActor|Properties")
	float MoveSpeed;


	UPROPERTY(EditAnywhere, Category = "MoveActor|Properties")
	float MinMoveSpeed;

	UPROPERTY(EditAnywhere, Category = "MoveActor|Properties")
	float MaxMoveSpeed;

	
	//이동 후 방향을 바꿀 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Properties")
	float MMoveDistance;

	UPROPERTY(EditAnywhere, Category = "MoveActor|Properties")
	float MinMoveDistance;

	UPROPERTY(EditAnywhere, Category = "MoveActor|Properties")
	float MaxMoveDistance;


	//현재 방향에서 어느정도 이동 했는지 확인.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Properties")
	float MoveDistance;


	//현재 방향에서 어느정도 이동 했는지 확인.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Properties")
	FVector MoveDirection;

	//숨기기 기능을 위한 bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Hide")
	bool HideFuntion;

	FTimerHandle HideTimerHandle;
	FTimerHandle ShowTimerHandle;

	void HideActor();
	void ShowActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Hide")
	float HideTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Hide")
	float ShowTime;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
