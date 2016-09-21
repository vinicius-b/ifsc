/*
 * UART.h
 *
 *  Created on: 1 de set de 2016
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_
#include <avr/io.h>

class UART {
public:
	UART();
	void put(char character);
	char get();
	~UART();
	void print(char *s);
	void println(char *s);
	void enable();
	void disable();
};

#endif /* UART_H_ */
