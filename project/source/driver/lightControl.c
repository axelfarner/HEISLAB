#include "lightControl.h"

bool hallLightUpStates[4] = {false};

bool hallLightDownStates[4] = {false};

bool cabLightStates[4] = {false};



void activateLight(int floor, ButtonType button){
    assert(floor<4 && floor>=0);
    switch(button) {
        case BUTTON_HALL_DOWN:
            hallLightUpStates[floor-1] = true;
            break;
        case BUTTON_HALL_UP:
            hallLightDownStates[floor-1] = true;
            break;
        case BUTTON_CAB:
            cabLightStates[floor-1] = true;
    }
    elevio_buttonLamp(floor,button, 1);
}


void deactivateLight(int floor){
    for(int i = 0; i < 3; i++){
    elevio_buttonLamp(floor, (ButtonType) i, 0);
    }

    hallLightDownStates[floor] = false;
    hallLightUpStates[floor] = false;
    cabLightStates[floor] = false;

    return;
}


void activateFloorLight(int floor){
    elevio_floorIndicator(floor);
    return;
}