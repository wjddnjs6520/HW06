// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportActor.h"

// Sets default values
ATeleportActor::ATeleportActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Component 구성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	FirstTeleportDelay = 3.0f;
	TeleportDelay = 3.0f;
}

// Called when the game starts or when spawned
void ATeleportActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	// TeleportGo 호출
	GetWorld()->GetTimerManager().SetTimer(
		TeleportFirstTimerHandle,
		this,
		&ATeleportActor::StartLoopTeleport,
		FirstTeleportDelay,
		false
	);

}

void ATeleportActor::Teleport()
{
	if (bIsForward)
	{
		SetActorLocation(GetActorLocation() + TeleprotDirection);
	}
	else
	{
		SetActorLocation(GetActorLocation() - TeleprotDirection);
	}
	bIsForward = !bIsForward; // 방향 반전

	EnableCollision();
}

void ATeleportActor::DisbleCollision()
{
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorHiddenInGame(true);
	// 0.2초 뒤에 충돌 다시 켜기
	GetWorld()->GetTimerManager().SetTimer(
		CollisionOnHandle,
		this,
		&ATeleportActor::Teleport,
		0.75f,
		false
	);
}


void ATeleportActor::EnableCollision()
{
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetActorHiddenInGame(false);
}



void ATeleportActor::StartLoopTeleport()
{
	// 첫 이동 실행
	DisbleCollision();

	// TeleportBack 호출
	GetWorld()->GetTimerManager().SetTimer(
		TeleportTimerHandle,
		this,
		&ATeleportActor::DisbleCollision,
		TeleportDelay,
		true
	);
}