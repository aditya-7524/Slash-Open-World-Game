// Fill out your copyright notice in the Description page of Project Settings.

#include "Slash1/DebugMacros.h"
#include "Items/Item.h"


// Sets default values
AItem::AItem() //:Amplitude(0.25f) [1] - can also initialize here
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);		//delta time = seconds per frame

	RunningTime += DeltaTime;  //keep track of total running time

	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);		//oscillate up and down over time, 0.5f = height multiplier
	
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));		//move the item up and down over time, based on the deltaZ calculated above, 0.f for X and Y means no movement in those axes

	DRAW_SPHERE_1FRAME(GetActorLocation());				//after each frame, it takes the current location, and offsets based on that
	DRAW_VECTOR_1FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100); //draw forward vector for 1 frame
}

