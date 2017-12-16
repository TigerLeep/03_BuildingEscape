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
    Owner = GetOwner();
}

void UOpenDoor::OpenDoor()
{
    SetDoorAngle(OpenAngle);
}

void UOpenDoor::CloseDoor()
{
    SetDoorAngle(0.0f);
}

void UOpenDoor::SetDoorAngle(float AngleOfDoor)
{
    Owner->SetActorRotation(FRotator(0.0f, AngleOfDoor, 0.0f));
}


void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        OpenDoor();
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }

    if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime >= DoorCloseDelay)
    {
        CloseDoor();
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

