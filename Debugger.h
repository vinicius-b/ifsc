/*
 * Debugger.h
 *
 *  Created on: 8 de set de 2016
 *      Author: alnuo
 */

#ifndef DEBUGGER_H_
#define DEBUGGER_H_

#include "UART.h"

class Debugger {
private:
  UART * output;
  long long baudrate;
public:
  Debugger(UART& out, long long baud = 19200)
    : output(out), baudrate(baud)
  {
    on();
  }

  template<typename T>
  void debug(T mesg) {
      output->println(mesg);
  }

  void on()  { output->enable(); }
  void off() { output->disable(); }
};

#endif /* DEBUGGER_H_ */
