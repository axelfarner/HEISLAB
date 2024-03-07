#pragma once
#include <stdbool.h>
#include "elevio.h"
#include "queue.h"
#include "inputController.h"
#include "lightControl.h"
#include <stdio.h>





int currentFloor;

bool doorIsOpen;

Direction serviceMode;

/// @brief runs elevator continously. Contains main loop. 
void runElevator();

void initializeElevator();