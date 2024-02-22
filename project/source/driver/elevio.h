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




/// @brief Initializes elevator 
void elevio_init(void);



/// @brief Sets motor direction, keeps motor going that direction until function called again with other parameter
/// @param[in] dirn Wanted direction of motor
void elevio_motorDirection(MotorDirection dirn);

/// @brief Sets inputted buttonType in inputted floor to on if value 1, and turns light of if value 0
/// @param[in] floor Floor of button which lamp is being set
/// @param[in] button Buttontype of button which lamp is being set
/// @param[in] value 1 if button lamp is being turned on, 0 if button lamp being turned of
void elevio_buttonLamp(int floor, ButtonType button, int value);


/// @brief Sets floor indicator lamp of inputted floor
/// @param[in] floor Current floor
void elevio_floorIndicator(int floor);


/// @brief Turns door light on and off
/// @param[in] value 1 if lamp being turned on, 0 if being turned off
void elevio_doorOpenLamp(int value);


/// @brief Turns stop button lamp on or off
/// @param[in] value 1 if stop button lamp being turned on, 0 if being turned off 
void elevio_stopLamp(int value);


/// @brief Checks if a specified button on a specified floor is pressed
/// @param[in] floor The floor of the button
/// @param[in] button The type of button (inside, outside up or outside down)
/// @return 1 if button is pressed, 0 if not
int elevio_callButton(int floor, ButtonType button);


/// @brief Checks if the elevator is on a floor
/// @return Current floor of elevator, -1 if elevator currently between floors
int elevio_floorSensor(void);

/// @brief Checks if the stop button is pressed 
/// @return 1 if stop button pressed, 0 if not
int elevio_stopButton(void);


/// @brief Chekcs if obstruction in the way 
/// @return 1 if obstruction, 0 if no obstruction
int elevio_obstruction(void);

