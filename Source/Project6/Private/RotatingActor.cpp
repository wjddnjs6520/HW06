// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Component 구성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	//기본 z축으로 돌기.
	RotateDirection = FRotator(0.0f, 1.0f, 0.0f);
	HideTime = 5.0f;
	ShowTime = 2.0f;
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	//랜덤 속도로 돌기
	RotateSpeed = FMath::RandRange(MinRotateSpeed, MaxRotateSpeed);

	if (HideFuntion) {
		// HideActor 호출
		GetWorld()->GetTimerManager().SetTimer(
			HideTimerHandle,
			this,
			&ARotatingActor::HideActor,
			HideTime,
			false
		);
	}
}

void ARotatingActor::HideActor()
{
	// 액터 숨김
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	// ShowActor 호출 타이머 설정
	GetWorld()->GetTimerManager().SetTimer(
		ShowTimerHandle,
		this,
		&ARotatingActor::ShowActor,
		ShowTime,
		false
	);
}

void ARotatingActor::ShowActor()
{
	// 액터 다시 보이기
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	// 다시 Hide 타이머 예약
	GetWorld()->GetTimerManager().SetTimer(
		HideTimerHandle,
		this,
		&ARotatingActor::HideActor,
		HideTime,
		false
	);
}



// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotateDirection * RotateSpeed * DeltaTime);

}

