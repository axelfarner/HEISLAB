#pragma once

#include "stdbool.h"
#include "elevio.h"
#include "stdio.h"

extern bool isElevatorMoving;

void moveUp();
void moveDown();
void stop();