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
	if(pin<=7){
			DDRD |= (1<<pin);
			port = &PORTD;
		}else if(pin>=8 && pin<=13){
			pin = pin-8;
			DDRB |= (1<<pin);
			port = &PORTB;
		 }else{
			pin = pin-14;
			DDRC |= (1<<pin);
			port = &PORTC;
		  }
}

void gpio::set(int val){
		if(val)
			*port |= (1<<pin);
		else
			*port &= ~(1<<pin);
}


int gpio::get(){
	if(pin<=7){
		 return PORTD;
	    }else if(pin>=8 && pin<=13){
	    	return PORTB;
	    }else {
	    	return PORTC;
	     }
}


gpio::~gpio(){}
