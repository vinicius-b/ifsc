/*
 * ADC.cpp
 *
 *  Created on: 22 de set de 2016
 *      Author: aluno
 */

#include "AD_conv.h"

AD_conv::AD_conv() {
	enable();
}

AD_conv::~AD_conv(){}

uint16_t AD_conv::read(){
	ADMUX =	0;
	ADMUX=(1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
	ADCSRA |= (1<<ADSC);
	ADCSRA |= (1<<ADATE);
	ADCSRA |= (1<<ADIE);
	ADCSRB |= (1 << ADTS0);
	ADCSRB |= (0 << ADTS1);
	ADCSRB |= (0 << ADTS2);

	while (ADCSRA & (1<<ADSC));
	uint16_t val = ADC;
	val = converter(val);
	return val;
}

uint16_t AD_conv::converter(uint16_t val){
	uint16_t v = (val*5)/1024;
	return v;
}

void AD_conv::enable(){
	ADCSRA = (1<<ADEN);
}



void AD_conv::disable(){
//	ADCSRB = (1 << 1);
//	ADCSRB = (1 << 2);
}
