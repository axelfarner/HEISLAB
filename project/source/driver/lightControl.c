#include "lightControl.h"
#include <assert.h>


void activateLight(int floor, ButtonType button){
    assert(floor<4 && floor>=0);
    elevio_buttonLamp(floor,button, 1);
}


void deactivateLight(int floor){
    for(int i = 0; i < 3; i++){
    elevio_buttonLamp(floor, (ButtonType) i, 0);
    }

    return;
}


void activateFloorLight(int floor){
    elevio_floorIndicator(floor);
    return;
}

void setStoplightState(int state) {
    if (state) {
        elevio_stopLamp(1);
    }
    else {
        elevio_stopLamp(0);
    }
}