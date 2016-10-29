/*
 * ADC.h
 *
 *  Created on: 29 de set de 2016
 *      Author: aluno
 */

#ifndef AD_CONV_H_
#define AD_CONV_H_

#include <avr/io.h>

class AD_conv{
public:
	AD_conv();
	~AD_conv();
	uint16_t read();
	uint16_t converter(uint16_t val);
	void enable();
	void disable();
};

#endif /* AD_CONV_H_ */
