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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")  /*can be edited per instance in the editor and read in blueprints,
							is now exposed to event graph, and category groups parameters for good organization*/
	float Amplitude = 0.25;	//how high the item moves up and down, can be assigned in constructor also [1]
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters") 
	float RunningTime;

	UFUNCTION(BlueprintCallable)		//can be called in blueprints
	float TransformedSin(float val);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))  //meta tag allows private variable to be edited in editor
	float TimeConstant = 5.f; //how fast the item moves up and down or period=2*PI/TimeConstant
};
