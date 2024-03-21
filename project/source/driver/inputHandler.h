#pragma once
#include "elevio.h"
#include "elevatorController.h"
#include "queue.h"
#include "stdio.h"

/// @brief Checks button states and creates queue entries for pressed buttons
/// @return -1 if stopButton is pressed, 0 otherwise
int processInput();