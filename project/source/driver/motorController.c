#include "motorController.h"

bool isElevatorMoving = false;

void moveUp() {
    // printf("Moving up\n");
    elevio_motorDirection(DIRN_UP);
    isElevatorMoving = true;
}
void moveDown() {
    // printf("Moving down\n");
    elevio_motorDirection(DIRN_DOWN);
    isElevatorMoving = true;
}
void stop() {
    // printf("Stopped moving\n");
    elevio_motorDirection(DIRN_STOP);
    isElevatorMoving = false;
}