#pragma once

typedef enum{
    UP = 0,
    DOWN = 1
} Direction;

int currentFloor;
Direction serviceMode;

void runElevator();