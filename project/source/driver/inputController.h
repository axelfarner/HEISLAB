#pragma once
#include "elevio.h"
#include "elevatorController.h"
#include "queue.h"

/*kan ha en Direction dir også, det egt bare flytter hvor man gjør logikken med finne direction fra 
knapp. Enten gjør man det når man oppretter en request eller når man setter requesten inn i queue.
Trenger vi egt dette i det hele tatt eller kan vi bare ha funksjonene fra queue i samme loop som 
sjekker om noen knapper er trykket inn
*/
struct Request{
    int floor;
    ButtonType button;
};

Request makeNextRequest(int floor, ButtonType button); 

int checkButtonStates();


