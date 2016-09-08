 /*
 * gpio.cpp
 *
 *  Created on: 31 de ago de 2016
 *      Author: aluno
 */
#include <stdio.h>
#include <avr/io.h>

#include "gpio.h"

gpio::gpio(int p, bool io): pin(p), in_out(io) {
	if(in_out){
		if (p >= 0 && p <= 7)
			DDRD = (1 << p);
		else if (p >=8 && p <= 13)
			DDRB = (1 << (p - 8));
		else if (p >= 14 && p <= 19)
			DDRC = (1 << (p - 14));
	}else{
			if (p >= 0 && p <= 7)
				DDRD &= ~p;
			else if (p >=8 && p <= 13)
				DDRB &= ~(p - 8);
			else if (p >= 14 && p <= 19)
				DDRC &=  ~(p - 14);
		}
}

void gpio::set(int val){

	if (pin >= 0 && pin <= 7)
		PORTD = (val << pin);
	else if (pin >=8 && pin <= 13)
		PORTB = (val << (pin-8));
	else if (pin >= 14 && pin <= 19)
		PORTC = (val << (pin - 14));
}

int gpio::get(){
	return pin;
}
gpio::~gpio(){

}

