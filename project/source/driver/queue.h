#pragma once

#include "stdbool.h"
#include "elevatorController.h"



/// @brief Adds a request to either up or down queue
/// @param[in] dir Direction of request
/// @param[in] floor Floor elevator needs to go to fulfill request 
void addToQueue(Direction dir, int floor);

/// @brief Checks if floor is in queue
/// @param[in] floor Floor that is being checked
/// @param[in] dir Queue that is being checked
/// @return 1 if in queue, 0 if not
bool isFloorInQueue(int floor, Direction dir);

void clearQueue();