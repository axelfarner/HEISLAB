// #ifndef ELEVATORCONTROLLER
// #define ELEVATORCONTROLLER

#pragma once

#include <stdbool.h>
#include "queue.h"
#include "motorController.h"
#include "stdio.h"

extern int currentFloor;

extern bool doorIsOpen;

extern Direction serviceMode;

/// @brief runs elevator continously. Contains main loop. 
void runElevator();

/// @brief initializes elevator control. Must be run before elevator can be started. 
void initializeElevator();
// #endif