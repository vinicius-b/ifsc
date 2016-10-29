/*
 * Timer.cpp
 *
 *  Created on: 29 de out de 2016
 *      Author: pc
 */

#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {

}

void Timer::init(){
	TCCR0B |= (1 << CS02)|(1 << CS00);
	TCNT0 = 0;

}

