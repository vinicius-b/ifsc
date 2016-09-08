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
	void set(int val);
	int get();
private:
	int pin;
	bool in_out;
};

#endif /* GPIO_H_ */
