/*
 * Circularbuffer.h
 *
 *  Created on: 29 de out de 2016
 *      Author: pc
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_


template <typename T>
class Circular_buffer {
public:
	Circular_buffer(){
		int i;
		for (i=0; i<sizeof(int); i++)
			buffer[i] = 0;
			pos=sizeof(int)-1;
	}
	virtual ~Circular_buffer();
	void push(T value){
		pos = ((pos == sizeof(int)-1) ? 0 : (pos+1));
		buffer[pos] = value;
	}
	T get(int i){
		int j;
		j = (pos +1 + i) % sizeof(int);
		return buffer[j];
	}
private:
	T buffer[sizeof(int)];
	int pos;
};

#endif /* CIRCULARBUFFER_H_ */
