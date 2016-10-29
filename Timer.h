/*
 * Timer.h
 *
 *  Created on: 29 de out de 2016
 *      Author: pc
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>

class Timer {
public:
	Timer();
	virtual ~Timer();
	void init();
private:
	int counter;
};

#endif /* TIMER_H_ */
