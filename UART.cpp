/*
 * UART.cpp
 *
 *  Created on: 1 de set de 2016
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>


UART::UART() {
	unsigned int baud = 19200;
	unsigned int ubrr = (F_CPU/(16 * baud))-1;
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	UCSRB |= (1<<4)|(1<<3);
	UCSRC |= (1 <<2)|(1<<1);

}

UART::~UART() {

}

void UART::put(char character){
	while(!(UCSRA & (1 << 5)));
	UDR = character;
}

char UART::get(){

}

