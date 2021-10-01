/*      Author: ffan005
 *  Partner(s) Name:
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
unsigned char cntavail = 0x00;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpC = 0x00;
unsigned char tmpD = 0x00;
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00; // since this time we want port C to be the output
while(1) {
        tmpA = (PINA & 0x08)>>3;
        tmpB = (PINA & 0x04)>>2;
        tmpC = (PINA & 0x02)>>1;
        tmpD = (PINA & 0x01);
        cntavail = 0x04 - (tmpA + tmpB + tmpC + tmpD);
        if(cntavail == 0x00){
                cntavail = 0x80;
        }
        //cntavail = 0x04 – (((PINA & 0x08)>>3) + ((PINA & 0x04)>>2)+ ((PINA & 0x02)>>1) + (PINA & 0x01));
        PORTC = cntavail;
}
return 0;

}
