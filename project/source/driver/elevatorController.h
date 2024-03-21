#pragma once
#include "elevio.h"
#include <stdbool.h>
#include "queue.h"
#include "motorController.h"
#include "stdio.h"
#include "lightControl.h"
#include "inputHandler.h"

extern int currentFloor;

extern bool doorIsOpen;

extern Direction serviceMode;

/// @brief Initializes elevator, then runs continous main loop controlling the elevator. 
void runElevator();
