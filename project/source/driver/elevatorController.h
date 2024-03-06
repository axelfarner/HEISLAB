#pragma once

typedef enum {
    UP = 1,
    DOWN = -1
} Direction;

int currentFloor;

bool doorIsOpen;

Direction serviceMode = UP;

/// @brief runs elevator continously. Contains main loop. 
void runElevator();