#include "inputController.h"

void createQueueEntry(ButtonType button, int floor);

int checkButtonStates(){
    if(elevio_stopButton()){
        return -1;
    }
    int state;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            state = elevio_callButton(i, (ButtonType) j);
            if(state){
                createQueueEntry((ButtonType) j, i);
            }
        }
    }
    return 0;
}

void createQueueEntry(ButtonType button, int floor){
    Direction dir;

    activateLight(floor, button);

    if(button == BUTTON_HALL_UP){
        dir = UP;
    } else if (button == BUTTON_HALL_DOWN){
        dir = DOWN;
    } else if(button == BUTTON_CAB){
        if(floor>currentFloor){
            dir = UP;
        } else if(floor<currentFloor){
            dir = DOWN;
        } 
    }
    addToQueue(dir, floor);
}
