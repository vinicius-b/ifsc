/*
 * gpio.h
 *
 *  Created on: 31 de ago de 2016
 *      Author: aluno
 */

#ifndef GPIO_H_
#define GPIO_H_

class gpio {
public:
	gpio(int p, bool io);
	~gpio();
	void on() { set(1); }
	void off() { set(0); }
	void set(int val);
	int get();
	volatile uint8_t *port;
private:
	int pin;
	bool in_out; //true: output , false: input
};

#endif /* GPIO_H_ */
