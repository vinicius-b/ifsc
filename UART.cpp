/*
 * UART.cpp
 *
 *  Created on: 1 de set de 2016
 *      Author: aluno
 */
#include <stdio.h>
#include <avr/io.h>
#include "UART.h"



UART::UART() {
	unsigned int baud = 19200;
	unsigned int ubrr = (F_CPU/(16ul * baud))-1;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0C |= (1 <<2)|(1<<1);
	enable();
}

UART::~UART() {

}

void UART::put(char character){
	while(!(UCSR0A & (1 << 5)));
	UDR0 = character;
}

char UART::get(){

}

void UART::enable(){
	UCSR0B |= (1<<4)|(1<<3);
}
void UART::disable(){
	UCSR0B &= ~((1<<4)|(1<<3));
}
void UART::print(const char *s){
	while(*s) {
		put(*s);
		s++;
	}
}

void UART::println(const char *s){
	print(s);
	put('\n');
}
