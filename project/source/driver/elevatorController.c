#include "elevatorController.h"

/// @brief Opens door for 3 seconds. Holds door open if stopbutton pressed
void openDoor();

/// @brief checks the floor sensor state. Updates currentFloor
/// @return state of floor sensor. -1 if between floors. 
int checkFloorSensor();

bool runQueue();

int moveElevator();

bool shouldStop() 

void initializeElevator(){
    elevio_init();
    
    // Turn off lights
    elevio_doorOpenLamp(0);
    
    for (int i = 0; i < 4; i++)
    {
        deactivateLight(i);
    }
    
    serviceMode = DOWN;
    moveDown();
    while(checkFloorSensor() == -1){ // this might be a problem >B-P
    }

    activateFloorLight(currentFloor);
    elevio_motorDirection(DIRN_STOP);
    printf("Initialization complete! \n ================================\n");
}

void runElevator() {
    while(true) {
        if (processInput() == -1) {

            elevio_motorDirection(DIRN_STOP);
            for (int i = 0; i<4; i++){
                deactivateLight(i);
            }

            if (checkFloorSensor() != -1) {
                openDoor();
            }
            // hopper tilbake til toppen
            continue;
        }
        if (shouldStop()) {
            stop();
            // activates lights
            deactivateLight(currentFloor);
            activateFloorLight(currentFloor);
            openDoor();
        } 

        if (!isElevatorMoving) {
            moveElevator();
        }
    }
};

bool shouldStop() {
    return isFloorInQueue(checkFloorSensor(), serviceMode);
}

int checkFloorSensor() {
    int sensorState = elevio_floorSensor();

    if (sensorState != -1) {
        currentFloor = sensorState;
    }
    return sensorState;
};

int moveElevator() {
    if (runQueue()) {
        int minFloor;
        if (serviceMode == UP) {
            serviceMode = DOWN;
            minFloor = 5;
        } else {
            serviceMode = UP;
            minFloor = -1;
        }
    }
}

bool runQueue() {
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
            if (floorInQueue) {
                moveUp();
            }
            break;
        
        case DOWN:
            for(int i = currentFloor-1; i > -1; i--) {
                if (isFloorInQueue(i, serviceMode)) {
                    floorInQueue = true;
                    break;
                }
            }
            if (floorInQueue) {
                moveDown();
            }
            break;
    }
    return !floorInQueue;
}

void openDoor() {
    // opens door
    elevio_doorOpenLamp(1);

    // sets status flag 
    doorIsOpen = true;

    // desired closing time for door
    int closeTime = time() + 4;

    while(time() < closeTime || elevio_obstruction()) {
        if (processInput() == -1) {
            closeTime = time() + 4;
            for (int i = 0; i<4; i++){
                deactivateLight(i);
            }
        }
    }

    elevio_doorOpenLamp(0);
    doorIsOpen = false;
};