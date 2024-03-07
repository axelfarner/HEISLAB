#include "queue.h"
#include <stdio.h>

bool upQueue[4] = {false, false, false, false};
bool downQueue[4] = {false, false, false, false};

void addToQueue(Direction dir, int floor) {
    if (floor < 0 || floor > 3) {
        return;
    }
    
    if (dir == UP){
        upQueue[floor] = true;
    } else if (dir == DOWN) {
        downQueue[floor] = true;
    }

    printQueues();
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


void printQueues() {
    printf("--------------------------------\n");
    printf("Up-queue: %d, %d, %d, %d\n", upQueue[0],upQueue[1],upQueue[2],upQueue[3]);
    printf("Down-queue: %d, %d, %d, %d\n", downQueue[0],downQueue[1],downQueue[2],downQueue[3]);
}