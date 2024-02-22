#pragma once

#include "stdbool.h"

typedef enum{
    UP = 0,
    DOWN = 1
} Direction;


void addToQueue(Direction dir, int floor);

bool isFloorInQueue(int floor, Direction dir);