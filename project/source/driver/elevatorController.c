#include "elevatorController.h"

/// @brief Opens door for 3 seconds. Holds door open if stopbutton pressed
void openDoor();

/// @brief checks the floor sensor state. Updates currentFloor
/// @return state of floor sensor. -1 if between floors. 
int checkFloorSensor();

void moveElevator();

void initializeElevator(){
    elevio_init();
    
    // Turn off lights
    elevio_doorOpenLamp(0);
    
    for (int i = 0; i < 4; i++)
    {
        deactivateLight(i);
    }
    
    serviceMode = DOWN;
    elevio_motorDirection(DIRN_DOWN);
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

        if (isFloorInQueue(checkFloorSensor(), serviceMode)) {
            elevio_motorDirection(DIRN_STOP);
            deactivateLight(currentFloor);
            activateFloorLight(currentFloor);
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
        elevio_motorDirection((MotorDirection) serviceMode); // casting serviceMode to MotorDirection

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

    // desired time to close door
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