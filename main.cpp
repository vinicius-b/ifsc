/*
 * main.cpp
 *
 *  Created on: 31 de ago de 2016
 *      Author: aluno
 */
#include "gpio.h"
#include <util/delay.h>

int main(){
	//false - saida
	//true - entrada

	gpio led(13,true);
	UART Serial();
	Debugger db(&Serial);

	while(1){
		led.set(1);
		_delay_ms(1000);
		db.debug("On!");
		led.set(0);
		_delay_ms(1000);
		db.debug("Off!");
	}

	return 0;
}


