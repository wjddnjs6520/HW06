// Fill out your copyright notice in the Description page of Project Settings.


#include "HideActor.h"

// Sets default values
AHideActor::AHideActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // Component 구성
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void AHideActor::BeginPlay()
{
    Super::BeginPlay();

    // 5초마다 HideActor 호출
    GetWorld()->GetTimerManager().SetTimer(
        HideTimerHandle,
        this,
        &AHideActor::HideActor,
        5.0f,
        true
    );
}


void AHideActor::HideActor()
{
    // 액터 숨김
    SetActorHiddenInGame(true);

    // 2초 뒤 ShowActor 호출 타이머 설정
    GetWorld()->GetTimerManager().SetTimer(
        ShowTimerHandle,
        this,
        &AHideActor::ShowActor,
        2.0f,
        false
    );
}

void AHideActor::ShowActor()
{
    // 액터 다시 보이기
    SetActorHiddenInGame(false);
}

