#pragma once


#define N_FLOORS 4

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;


//initializes elevator (use in the beginning)
void elevio_init(void);

//sets motor direction, keeps motor going that direction until called otherwise
void elevio_motorDirection(MotorDirection dirn);
//sets inputted buttonType in inputted floor to on if value 1, and turns light of value 0
void elevio_buttonLamp(int floor, ButtonType button, int value);
//sets floor indicator lamp of input
void elevio_floorIndicator(int floor);
//if input value 1: door light on, value 0: door light of
void elevio_doorOpenLamp(int value);
 //if value 1: turns on stop lamp, if value 0: turns of stop lamp
void elevio_stopLamp(int value);

//uses floor and buttontype, and returns 1 is buttontype is pressed in floor, 0 if not
int elevio_callButton(int floor, ButtonType button);
//returns current floor, and -1 if between floors
int elevio_floorSensor(void);
//returns 1 if stopButton pressed, 0 if not
int elevio_stopButton(void);
//returns 1 if obstruction, 0 if not
int elevio_obstruction(void);

