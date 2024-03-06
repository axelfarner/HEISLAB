#include "elevatorController.h"
#include "elevio.h"
#include "queue.h"

/// @brief Opens door for 3 seconds. Holds door open if stopbutton pressed
void openDoor();

/// @brief checks the floor sensor state. Updates currentFloor
/// @return state of floor sensor. -1 if between floors. 
int checkFloorSensor();

void moveElevator();


void runElevator() {
    while(true) {
        if (checkButtonStates() == -1) {

            clearQueue();
            elevio_motorDirection(DIRN_STOP);

            if (checkFloorSensor() != -1) {
                openDoor();
            }
            // hopper tilbake til toppen
            continue;
        }

        if (isFloorInQueue(checkFloorSensor(), serviceMode)) {
            elevio_motorDirection(DIRN_STOP);
            deactivateLight(currentFloor);
            openDoor();
        }

        moveElevator();
    }
};


int checkFloorSensor() {
    int sensorState = elevio_floorSensor();

    if (sensorState != -1) {
        currentFloor = sensorState;
    }
    return sensorState;
};


void moveElevator() {
    bool floorInQueue = false;

    switch (serviceMode)
    {
        case UP:
            for(int i = currentFloor+1; i < 4; i++) {
                if (isFloorInQueue(i, serviceMode)) {
                    floorInQueue = true;
                    break;
                }
            }
            break;
        
        case DOWN:
            for(int i = currentFloor-1; i > -1; i--) {
                if (isFloorInQueue(i, serviceMode)) {
                    floorInQueue = true;
                    break;
                }
            }
            break;
    }

    if (floorInQueue) {
        elevio_motorDirection((MotorDirection) serviceMode);
    } else {
        // bytter serviceMode
        if (serviceMode == UP) {
            serviceMode =  DOWN;
        } else {
            serviceMode = UP;
        }
    }
}



void openDoor() {
    // opens door
    elevio_doorOpenLamp(1);
    doorIsOpen = true;
    // desired time to close
    int closeTime = time() + 4;

    while(time() < closeTime) {
        if (checkButtonStates() == -1) {
            closeTime = time() + 4;
        }
    }

    elevio_doorOpenLamp(0);
    doorIsOpen = false;
};