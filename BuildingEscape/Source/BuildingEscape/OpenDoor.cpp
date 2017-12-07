// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
    Super::BeginPlay();
    
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
    auto ObjectName = GetOwner()->GetName();
    auto NewRotator = FRotator(0.0f, -60.0f, 0.0f);
    GetOwner()->SetActorRotation(NewRotator);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        OpenDoor();
    }

    //auto OwnerRotator = GetOwner()->GetActorRotation();
    //if (OwnerRotator.Yaw > -60.f)
    //{
    //    OwnerRotator.Yaw -= (15.0f * DeltaTime);
    //}
    //if (OwnerRotator.Yaw < -60.f)
    //{
    //    OwnerRotator.Yaw = -60.0;
    //}
    //GetOwner()->SetActorRotation(OwnerRotator);
}

