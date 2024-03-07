#pragma once
#include <stdbool.h>


typedef enum {
    UP = 1,
    DOWN = -1
} Direction;

int currentFloor;

bool doorIsOpen;

Direction serviceMode;

/// @brief runs elevator continously. Contains main loop. 
void runElevator();

void initializeElevator();