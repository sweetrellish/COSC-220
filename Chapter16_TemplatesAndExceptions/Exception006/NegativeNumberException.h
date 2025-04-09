/*
 Author: Don Spickler
 Creation Date: 1/27/2022
 Last Update: 1/27/2022
 Description: Specification for the NegativeNumberException class.
 */

#ifndef NEGATIVENUMBEREXCEPTION_H_
#define NEGATIVENUMBEREXCEPTION_H_

#include "ExceptionSystem.h"

class NegativeNumberException : public ExceptionSystem {
public:
  NegativeNumberException(string em = "");
  virtual ~NegativeNumberException();
};

#endif /* NEGATIVENUMBEREXCEPTION_H_ */
