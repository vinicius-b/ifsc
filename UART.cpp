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
	unsigned int ubrr = (F_CPU/(16ul * baud))-1;
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;


	UCSRC |= (1 <<2)|(1<<1);
	enable();
}

UART::~UART() {

}

void UART::put(char character){
	while(!(UCSRA & (1 << 5)));
	UDR = character;
}

char UART::get(){

}

void UART::enable(){
	UCSRB |= (1<<4)|(1<<3);
}
void UART::disable(){
	UCSRB &= ~((1<<4)|(1<<3));
}
void UART::print(char *s){
	while(*s) {
		put(*s);
		s++;
	}
}

void UART::println(char *s){
	print(s);
	put('\n');
}
