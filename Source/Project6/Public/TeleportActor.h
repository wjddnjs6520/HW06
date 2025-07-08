// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportActor.generated.h"


UCLASS()
class PROJECT6_API ATeleportActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleportActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//Scene Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TeleportActor|Components")
	USceneComponent* SceneRoot;
	// Static Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	//액터 처음 위치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportActor|Properties")
	FVector StartLocation;
	//움직일 방향
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportActor|Properties")
	FVector TeleprotDirection;


	// 타이머 핸들
	FTimerHandle TeleportFirstTimerHandle;
	FTimerHandle TeleportTimerHandle;
	FTimerHandle CollisionOnHandle;

	//텔레포트 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportActor|Properties")
	float TeleportDelay;
	//처음 텔레포트 딜레이
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportActor|Properties")
	float FirstTeleportDelay;

	//텔레포트 함수
	void Teleport();
	//왔다갔다 루프 시작 함수
	void StartLoopTeleport();
	void EnableCollision();
	void DisbleCollision();
	//방향 결정 부울
	bool bIsForward = true;
};
