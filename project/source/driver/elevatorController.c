#include "elevatorController.h"

/// @brief Opens door for 3 seconds. Holds door open if stopbutton pressed
void openDoor();

/// @brief checks the floor sensor state. Updates currentFloor
/// @return state of floor sensor. -1 if between floors.
int checkFloorSensor();

/// @brief Moves elevator in direction of serviceMode, if there are queued floors in "serviceMode direction" beyond current floor.
/// @return 1 if moved, 0 if not.
bool runQueue();

/// @brief Handles all elevator movement. Starts movement in either up or down direction, if there are floors in the queue
void moveElevator();

/// @brief Checks whether the elevator should stop at currentfloor
/// @return 1 if the elevator should stop, 0 if not 
bool shouldStop();

/// @brief Handles ordinary stops. Checks input continously while running, ends when door is closed.
void stopAtFloor();

/// @brief Asserted when elevator is switching serviceMode, negated when elevator stops for the first time. 
bool inTransitionMode = false;

/// @brief Last floor elevator reached
int currentFloor = 0;

/// @brief Asserted while door is open, negated when door closes
bool doorIsOpen = false;

/// @brief Current service mode
Direction serviceMode = DOWN;

void initializeElevator()
{
    elevio_init();

    // Turn off lights
    elevio_doorOpenLamp(0);

    for (int i = 0; i < 4; i++)
    {
        deactivateLight(i);
    }

    serviceMode = DOWN;
    moveDown();
    while (checkFloorSensor() == -1)
    { // this might be a problem >B-P
    }

    activateFloorLight(currentFloor);
    stop();
    inTransitionMode = false;
    printf("Initialization complete! \n ================================\n");
}

void runElevator()
{
    initializeElevator();
    while (true)
    {

        if (processInput() == -1)
        {
            setStoplightState(1);
            stop();
            for (int i = 0; i < 4; i++)
            {
                deactivateLight(i);
            }

            if (checkFloorSensor() != -1)
            {
                openDoor();
            }
            // hopper tilbake til toppen
            continue;
        }

        setStoplightState(0);

        if (checkFloorSensor() != -1) {
            if (shouldStop())
            {
                stopAtFloor();
            }
        }
        
        if (!isElevatorMoving)
        {
            moveElevator();
        }
    }
}

void stopAtFloor() {
    stop();
    // removes entries at current floor from queue
    
    removeFromQueue(currentFloor);
    printQueues();
    openDoor();
}

bool shouldStop()
{
    bool shouldStop = 0;

    if (isFloorInQueue(currentFloor, serviceMode))
    {
        shouldStop = 1;

        if (inTransitionMode)
        {

            if (queueEntryBeyondFloor(serviceMode, currentFloor))
            {
                shouldStop = false;
            }

            // if elevator stops, then it has left transition Mode
            inTransitionMode = !shouldStop;
        }
    }
    return shouldStop;
}

int checkFloorSensor()
{
    int sensorState = elevio_floorSensor();

    if (sensorState != -1)
    {
        currentFloor = sensorState;
        deactivateLight(sensorState);
        activateFloorLight(sensorState);
    }
    return sensorState;
}

void moveElevator()
{
    if (!runQueue())
    {
        // swaps servicemode
        serviceMode = (serviceMode == DOWN) ? UP : DOWN;

        if (queueEntryBeyondFloor(serviceMode, currentFloor))
        {
            inTransitionMode = true;
            (serviceMode == DOWN) ? moveUp() : moveDown();
        }
    }
}

/// @brief Tries to move to next entry in queue, if any exist
/// @return 1 if moved, 0 if not.
bool runQueue()
{
    bool floorInQueue = false;

    switch (serviceMode)
    {
    case UP:
        for (int i = currentFloor; i < 4; i++)
        {
            if (isFloorInQueue(i, serviceMode))
            {
                floorInQueue = true;
                break;
            }
        }
        if (floorInQueue)
        {
            moveUp();
        }
        break;

    case DOWN:
        for (int i = currentFloor; i > -1; i--)
        {
            if (isFloorInQueue(i, serviceMode))
            {
                floorInQueue = true;
                break;
            }
        }
        if (floorInQueue)
        {
            moveDown();
        }
        break;
    }
    return floorInQueue;
}

void openDoor()
{
    // opens door
    elevio_doorOpenLamp(1);

    // sets status flag
    doorIsOpen = true;
    // desired closing time for door
    int closeTime = time(NULL) + 4;

    // printf("Door opened\n");

    while (time(NULL) < closeTime || elevio_obstruction())
    {
        if (processInput() == -1)
        {
            closeTime = time(NULL) + 4;
            for (int i = 0; i < 4; i++)
            {
                deactivateLight(i);
            }
            setStoplightState(1);
            continue;
        }
        setStoplightState(0);
    }

    elevio_doorOpenLamp(0);
    doorIsOpen = false;
    // printf("Door closed\n");
}