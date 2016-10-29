/*
 * Queue.h
 *
 *  Created on: 29 de out de 2016
 *      Author: pc
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>

template <typename T>
class Queue {
public:
	Queue();
	virtual ~Queue();
	void push(T value){
		if(length() == 0){
			buffer[len] = value;
			head = value;
			tail = value;
			len++;
		}
		else{
			buffer[len+1] = value;
			head = buffer[0];
			tail = value;
			len++;
		}
	}
	T pop(){
		T value;

		if(length() == 0)
			printf("Erro, fila vazia\n");
		else if(length() == 1){
			value = buffer[len];
			buffer[len] = NULL;
			head = NULL;
			tail = NULL;
			len--;
		}
		else{
			value = buffer[len];
			buffer[len] = NULL;
			head = buffer[0];
			tail = buffer[len-1];
			len--;
		}
		return value;

	}
	int length(){
		return len;
	}
private:
	T buffer[sizeof(int)];
	int head;
	int tail;
	int len;
};

#endif /* QUEUE_H_ */
