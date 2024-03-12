#include "motorController.h"

bool isElevatorMoving = false;

void moveUp() {
    elevio_motorDirection(DIRN_UP);
    isElevatorMoving = true;
}
void moveDown() {
    elevio_motorDirection(DIRN_DOWN);
    isElevatorMoving = true;
}
void stop() {
    elevio_motorDirection(DIRN_STOP);
    isElevatorMoving = false;
}