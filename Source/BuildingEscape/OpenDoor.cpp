// Copyright Kids Hide Away 2019


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	UOpenDoor::CloseDoor(); 
	ActorThatOpensTheDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}
// Called when the game starts
void UOpenDoor::OpenDoor()
{   
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f)); 
}
// Called when the game starts
void UOpenDoor::CloseDoor()
{  
	Owner->SetActorRotation(FRotator(0.0f, CloseAngle, 0.0f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// video notes:
	// write if (PressurePlate && PressurePlate-> ...) to null check if getting crashes.
	// also check Trigger Volume is set. 7 minutes 16 second
	//Poll the Trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpensTheDoor))
	{
		// If the ActorThatOpensTheDoor is in the volume
		UOpenDoor::OpenDoor(); 
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
		{
			UOpenDoor::CloseDoor();
		}
	}
	// ...DoorCloseDelay GetWorld()->GetTimeSeconds(0);
}

