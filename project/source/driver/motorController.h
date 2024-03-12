#pragma once

#include "stdbool.h"
#include "elevio.h"
#include "stdio.h"

/// @brief Movement flag. True if elevator is moving either up or down, 0 if stopped
extern bool isElevatorMoving;

/// @brief Starts motor movement up 
void moveUp();
/// @brief Starts motor movement down
void moveDown();
/// @brief Stops motor movement
void stop();