// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableActor.h"

// Sets default values
AMovableActor::AMovableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Component 구성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//초기 변수들 구성
	MoveDistance = 0;
	MoveDirection = FVector(1.0f, 0.0f, 0.0f);
	HideFuntion = false;
	HideTime = 5.0f;
	ShowTime = 2.0f;
}

// Called when the game starts or when spawned
void AMovableActor::BeginPlay()
{
	Super::BeginPlay();
	//랜덤 변수 설정.
	MoveSpeed = FMath::RandRange(MinMoveSpeed, MaxMoveSpeed);
	MMoveDistance = FMath::RandRange(MinMoveDistance, MaxMoveDistance);
	StartLocation = GetActorLocation();
	if (HideFuntion) {
		// 5초마다 HideActor 호출
		GetWorld()->GetTimerManager().SetTimer(
			HideTimerHandle,
			this,
			&AMovableActor::HideActor,
			HideTime,
			true
		);
	}
	

}

void AMovableActor::HideActor()
{
	// 액터 숨김
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	// 2초 뒤 ShowActor 호출 타이머 설정
	GetWorld()->GetTimerManager().SetTimer(
		ShowTimerHandle,
		this,
		&AMovableActor::ShowActor,
		ShowTime,
		false
	);
}

void AMovableActor::ShowActor()
{
	// 액터 다시 보이기
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}




// Called every frame
void AMovableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveDistance < MMoveDistance) {
		//이동 거리 계산
		MoveDistance += (MoveDirection * MoveSpeed * DeltaTime).Size();
		//이동
		AddActorWorldOffset(MoveDirection * MoveSpeed * DeltaTime);
	}
	else {
		MoveDirection *= (-1);
		MoveDistance = 0;
	}

}

