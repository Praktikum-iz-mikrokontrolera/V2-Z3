#include "mbed.h"

DigitalOut dioda1(PA_11);
DigitalOut dioda2(PB_15);

int vremeDioda1 = 0;
int vremeDioda2 = 0;

void ISR_taster1() {
    dioda1 = 1;
    vremeDioda1 = 3000;
}

void ISR_taster2() {
    dioda2 = 1;
    vremeDioda2 = 5000;
}

int main()
{
    InterruptIn taster1(PC_9);
    InterruptIn taster2(PC_8);
    taster1.fall(&ISR_taster1);
    taster2.fall(&ISR_taster2);

    while (true) {
        if(vremeDioda1 > 0) {
            vremeDioda1--;
        }else{
            dioda1 = 0;
        }

        if(vremeDioda2 > 0) {
            vremeDioda2--;
        }else{
            dioda2 = 0;
        }

        ThisThread::sleep_for(1ms);
    }
}

    
