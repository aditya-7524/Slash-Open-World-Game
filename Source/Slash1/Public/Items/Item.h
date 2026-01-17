// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH1_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleDefaultsOnly) //can only be seen in the defaults panel, not editable
	float RunningTime;
	UPROPERTY(EditAnywhere)  //can only be edited in BP and World instance
	float Amplitude = 0.25;	//how high the item moves up and down, can be assigned in constructor also [1]

	UPROPERTY(EditAnywhere)  //can only be edited per instance in the editor, not during gameplay
	float TimeConstant = 5.f; //how fast the item moves up and down or period=2*PI/TimeConstant
};
