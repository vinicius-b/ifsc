/*
 * UART.cpp
 *
 *  Created on: 1 de set de 2016
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>


UART::UART(unsigned baud, unsigned int data_size, unsigned int parity, unsigned int stop_bit) {
	UBRRH = (baud>>8);
	UBRRL = baud;

	UCSRB = (1<<RXEN)|(1<<TXEN);


}

UART::~UART() {

}

void UART::put(char character){

}

char UART::get(){

}

