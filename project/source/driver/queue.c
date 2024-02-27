#include "queue.h"

bool upQueue[4] = {false};
bool downQueue[4] = {false};

//Skal det være floor-1 eller floor
void addToQueue(Direction dir, int floor){
    if (dir == UP){
        upQueue[floor] = true;
    } else if (dir == DOWN) {
        downQueue[floor] = true;
    }
    return;
}

//samme her, floor-1 eller floor
bool isFloorInQueue(int floor, Direction dir){
    if(dir==DOWN && (downQueue[floor-1]==true)){
        return true;
    } else if (dir==UP && (upQueue[floor-1]==true)){
        return true;
    } else {return false;}
}