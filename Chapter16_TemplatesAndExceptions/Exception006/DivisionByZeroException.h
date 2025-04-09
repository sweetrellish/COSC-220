/*
 Author: Don Spickler
 Creation Date: 1/27/2022
 Last Update: 1/27/2022
 Description: Specification for the DivisionByZeroException class.
 */

#ifndef DIVISIONBYZEROEXCEPTION_H_
#define DIVISIONBYZEROEXCEPTION_H_

#include "ExceptionSystem.h"

class DivisionByZeroException : public ExceptionSystem {
public:
  DivisionByZeroException(string em = "");
  virtual ~DivisionByZeroException();
};

#endif /* DIVISIONBYZEROEXCEPTION_H_ */
