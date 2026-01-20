// Fill out your copyright notice in the Description page of Project Settings.

#include "Slash1/DebugMacros.h"
#include "Items/Item.h"


// Sets default values
AItem::AItem() //:Amplitude(0.25f) [1] - can also initialize here
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComp")); //creates the mesh component and assigns it to the ItemMesh pointer
	RootComponent = ItemMesh; //sets the root component to be the mesh component
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);		//delta time = seconds per frame
	RunningTime += DeltaTime;  //keep track of total running time

	
}

