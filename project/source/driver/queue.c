#include "queue.h"

bool upQueue[4] = {false};
bool downQueue[4] = {false};

void addToQueue(Direction dir, int floor) {
    if (floor < 0 || floor > 3) {
        return;
    }

    if (dir == UP){
        upQueue[floor] = true;
    } else if (dir == DOWN) {
        downQueue[floor] = true;
    }
    return;
}

bool isFloorInQueue(int floor, Direction dir) {
    if (floor < 0 || floor > 3) {
        return false;
    }

    if (dir==DOWN && (downQueue[floor]==true)) {
        return true;

    } else if (dir==UP && (upQueue[floor]==true)) {
        return true;

    } else {
        return false;
    }
}

void clearQueue() {
    for (int i = 0; i < 4; i++)
    {
        upQueue[i] = false;
        downQueue[i] = false;
    }   
}