#include "Activity1.h"
void SEAT_CHECKING(){
    ddrd|=(1<<PD0); //Setting PDO pin
    ddrd&=~(1<<PD1); //clearing PD1 pin
    portd|=(1<<PD1); //Setting PD1 pin
    ddrd&=~(1<<PD2); //clearing PD2 pin
    portd|=(1<<PD2); //Setting PD2 pin
}
