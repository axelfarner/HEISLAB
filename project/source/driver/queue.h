#pragma once
#include "stdbool.h"

typedef enum
{
    UP = 1,
    DOWN = -1
} Direction;
#include "elevatorController.h" // included to see flags, must be included after Direction is defined

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

/// @brief Removes specific entry from queue
/// @param dir Working mode
/// @param floor Floor where entry should be removed
void removeFromQueue(Direction dir, int floor);

/// @brief clears all entries from all queues
void clearQueue();

/// @brief checks whether the queue contains a floor "beyond" a specified floor. If direction is down, then check downQueue for entries ABOVE floor. If direction is up, check upQueue for entries BELOW floor.
/// @param dir
/// @param floor
/// @return 1 if floor exists, 0 if not
bool queueEntryBeyondFloor(Direction dir, int floor);

/// @brief prints both queues, for debug :)
void printQueues();