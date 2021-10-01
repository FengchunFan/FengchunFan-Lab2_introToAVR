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
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpC = 0x00;
unsigned char tmpD = 0x00;
//unsigned char tWeight = 0x00;
unsigned char tmpE = 0x00;
unsigned short tWeight = 0x00;
unsigned char tmpF = 0x00;

DDRA = 0x00; PORTA = 0xFF;
DDRD = 0xFF; PORTD = 0x00; // since this time we want port C to be the output
DDRB = 0x00; PORTB = 0xFF;
DDRC = 0x00; PORTC = 0xFF;

while(1) {
tmpA = PINA;
tmpB = PINB;
tmpC = PINC;
tWeight = tmpA + tmpB + tmpC;
  if(tWeight > 0x8C){
  tmpD = 0x01;  //PD0 = 1;
}
  if(((tmpA - tmpC) > 80) || ((tmpC - tmpA) > 80)){
  tmpE = 0x02;  //PD1 = 1;
}

tmpF = tWeight & 0xFC; //to keep the last two digit 0 for total weight
PORTD = (tmpD | tmpE | tmpF);
}
return 0;
}
