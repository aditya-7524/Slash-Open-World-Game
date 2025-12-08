// Fill out your copyright notice in the Description page of Project Settings.

#include "Slash1/DebugMacros.h"
#include "Items/Item.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	
	UWorld* World = GetWorld();
	
	//SetActorLocation(FVector(0.f, 0.f, 50.f));
	//FVector Fwd = GetActorForwardVector();
	//FVector Loc = GetActorLocation();
	//DRAW_SPHERE(Loc);
	//DRAW_LINE(Loc, Loc + Fwd * 100.f);
	//DRAW_POINT(Loc+Fwd*100.f);
	//DRAW_VECTOR(Loc, Loc + Fwd * 100.f);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);		//Delta time = seconds per frame

	//movt rate in units of cm/s
	float movtRate = 50.f;
	float rotRate = 45.f;

	//movtRate*DeltaTime(cm/s * s/frame = cm/frame); this is done instead of a normal x.f parameter in the below function so that changing fps doesnt change movt spd
	AddActorWorldOffset(FVector(movtRate*DeltaTime, 0.f, 0.f));		//since lifetime is -1.f, after each frame, it moves by the given parameters
	AddActorWorldRotation(FRotator(0.f, rotRate * DeltaTime,0.f));
	DRAW_SPHERE_1FRAME(GetActorLocation());				//after each frame, it takes the current location, and offsets based on that
	DRAW_VECTOR_1FRAME(GetActorLocation(), GetActorLocation()+ GetActorForwardVector()*100);
}

