#pragma once

#include "stdbool.h"
#include "elevio.h"

/// @brief Switches on the light with given buttontype in given floor
/// @param[in] floor Floor of light being turned on 
/// @param[in] button Buttontype of button being turned on
void activateLight(int floor, ButtonType button);

/// @brief Deactivates all lights associated with given floor, except indicator light
/// @param[in] floor Floor of lights being turned off
void deactivateLight(int floor);

/// @brief Turns indicator light on at given floor
/// @param[in] floor Current floor 
void activateFloorLight(int floor);