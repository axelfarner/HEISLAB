#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevatorController.h"
#include "driver/inputController.h"



int main() {

    initializeElevator();

    while(19) {
        processInput();
    }

    // runElevator();
    return 0;
}
