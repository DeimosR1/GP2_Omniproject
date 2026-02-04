// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorClasses/Actors/MyActor.h"

#include "ToolContextInterfaces.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::SpawnActor()
{
	FActorSpawnParameters spawnParameters;
	spawnParameters.Owner = this;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AMyActor>(Spawnable,SpawnLocation,FRotator::ZeroRotator, spawnParameters);
}


