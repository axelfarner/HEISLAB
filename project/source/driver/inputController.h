#pragma once
#include "elevio.h"
#include "elevatorController.h"
#include "queue.h"

/// @brief checks button states. Creates queue entries
/// @return -1 if stopButton is pressed, 0 otherwise
int processInput();