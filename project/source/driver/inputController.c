#include "inputController.h"

void createQueueEntry(ButtonType button, int floor);

int processInput() {
    if (elevio_stopButton()) {
        clearQueue();
        return -1;
    }
    int state;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++) {
            state = elevio_callButton(i, (ButtonType) j);
            if (state) {
                createQueueEntry((ButtonType) j, i);
            }
        }
    }
    return 0;
}

void createQueueEntry(ButtonType button, int floor){
    
    Direction dir;

    switch (button)
    {
    case BUTTON_HALL_UP:
        dir = UP;
        break;

    case BUTTON_HALL_DOWN:
        dir = DOWN;
        break;

    case BUTTON_CAB:

        if (floor > currentFloor) 
        {
            dir = UP;
        } else if (floor < currentFloor)
        {
            dir = DOWN;
        } else 
        {
            // hvis etasjen er nåværende etasje, og døren er åpen, do nothing
            if (doorIsOpen) {
                return;
            }


            switch (serviceMode)
            {
            case DOWN:
                dir = UP;
                break;
            
            case UP:
                dir = DOWN;
                break;
            }
        }
        break;
    }

    activateLight(floor, button);
    addToQueue(dir, floor);
}
