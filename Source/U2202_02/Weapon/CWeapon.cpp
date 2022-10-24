// Fill out your copyright notice in the Description page of Project Settings.


#include "CWeapon.h"

// Sets default values
ACWeapon::ACWeapon()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	OwnerCharacter = Cast<ACharacter*>(TryGetPawnOwner());
}

// Called when the game starts or when spawned
void ACWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

