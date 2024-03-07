#pragma once

#include "stdbool.h"

typedef enum {
    UP = 1,
    DOWN = -1
} Direction;

/// @brief Adds a request to either up or down queue
/// @param[in] dir Direction of request
/// @param[in] floor Floor elevator needs to go to fulfill request 
/// @warning If floor is larger than 3 or smaller than one, does nothing. No error is thrown
void addToQueue(Direction dir, int floor);

/// @brief Checks if floor is in queue
/// @param[in] floor Floor that is being checked
/// @param[in] dir Queue that is being checked
/// @return 1 if in queue, 0 if not
/// @warning If floor is larger than 3 or smaller than one, returns 0;
bool isFloorInQueue(int floor, Direction dir);

/// @brief clears all entries from all queues
void clearQueue();

/// @brief prints both queues, for debug :)
void printQueues();