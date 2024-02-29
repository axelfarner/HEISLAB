#pragma once

typedef enum{
    UP = 1,
    DOWN = -1
} Direction;

int stop = 0;

int currentFloor;
Direction serviceMode = UP;

void runElevator();

int checkFloor();

void openDoor();

int moreFloorsInDirection;
void runQueue();