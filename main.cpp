/*
 * main.cpp
 *
 *  Created on: 31 de ago de 2016
 *      Author: aluno
 */
#include <util/delay.h>

#include "AD_conv.h"
#include "gpio.h"
#include "UART.h"
#include "Debugger.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	//false - entrada
	//true - saida
	//pot pin A0
	//led pin 13

	gpio led(13,true);
	UART Serial;
	Debugger db(&Serial);
	AD_conv ad_conv;
	char buffer [10];
	const char* val_s;
	while(1){
		uint16_t val = ad_conv.read();
		sprintf(buffer,"%d", val);
		if(val >= 3){
			led.on();
			db.debug(buffer);
		}else{
			led.off();
			db.debug(buffer);
		}

	}

	return 0;
}
