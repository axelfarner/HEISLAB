#include "elevatorController.h"
#include "elevio.h"
#include "queue.h"



void runElevator() {

    elevio_motorDirection(DIRN_UP);

    while(1) {
        if (checkButtonStates() == -1) {
            clearQueue();
            elevio_motorDirection(DIRN_STOP);
            if (checkFloor() != -1) {
                openDoor();
                //dette kan være et problem, mulig døra spiser folk (kun hvert tredje sekund)
            }
            continue;
        }
        checkFloor();

        runQueue();



    }




};


int checkFloor(){
    int sensorState = elevio_floorSensor();

    if (sensorState != -1) {
        currentFloor = sensorState;
    }
    return sensorState;

};


void runQueue() {
    moreFloorsInDirection = false;
    switch (serviceMode)
    {
    case UP:
        for(int queuedFloors = currentFloor; queuedFloors<4; queuedFloors++) {
            if (isFloorInQueue(queuedFloors, serviceMode)) {
                moreFloorsInDirection = true;
            }
        }
        if(moreFloorsInDirection){elevio_motorDirection(DIRN_UP);}
        break;
    
    case DOWN:
        for(int queuedFloors = currentFloor; queuedFloors<4; queuedFloors++) {
            if (isFloorInQueue(queuedFloors, serviceMode)) {
                moreFloorsInDirection = true;
            }
        }
        if(moreFloorsInDirection){elevio_motorDirection(DIRN_UP);}
        break;
    }

}



void openDoor() {
    elevio_doorOpenLamp(1);
    sleep(3);
    elevio_doorOpenLamp(0);
};