/*
 * UART.h
 *
 *  Created on: 1 de set de 2016
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_

class UART {
public:
	UART(unsigned baud, unsigned int data_size, unsigned int parity, unsigned int stop_bit);
	void put(char character);
	char get();
	~UART();
};

#endif /* UART_H_ */
