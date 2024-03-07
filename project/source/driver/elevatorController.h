#pragma once
#include <stdbool.h>
#include "elevio.h"
#include "queue.h"
#include "inputController.h"
#include "lightControl.h"
#include <stdio.h>
#include "motorController.h"

int currentFloor;

bool doorIsOpen;

Direction serviceMode;

/// @brief runs elevator continously. Contains main loop. 
void runElevator();

/// @brief initializes elevator control. Must be run before elevator can be started. 
void initializeElevator();