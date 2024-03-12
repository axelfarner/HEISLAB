#pragma once
#include "elevio.h"
#include "elevatorController.h"
#include "queue.h"
#include "stdio.h"

/// @brief Checks button states and creates queue entries if buttons are pressed. 
/// @return -1 if stopButton is pressed, 0 otherwise
int processInput();