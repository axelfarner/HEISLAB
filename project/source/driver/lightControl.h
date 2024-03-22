#pragma once

#include "stdbool.h"
#include "elevio.h"

/// @brief Switches on the light for given buttontype in given floor
/// @param[in] floor Floor of light being turned on 
/// @param[in] button Buttontype of button being turned on
void activateLight(int floor, ButtonType button);

/// @brief Deactivates all button lights associated with given floor
/// @param[in] floor Floor of lights to turn off
void deactivateLight(int floor);

/// @brief Turns indicator light on at given floor
/// @param[in] floor Current floor 
void activateFloorLight(int floor);

/// @brief Turns stop light on or off
/// @param[in] state if 0 turns light off, otherwise turns on   
void setStoplightState(int state);