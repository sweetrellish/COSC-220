/*
 Author: Don Spickler
 Creation Date: 1/27/2022
 Last Update: 1/27/2022
 */

#include "DivisionByZeroException.h"

/*
 Description: Constructor
 Parameters: em - the error message.
 Return: None
 */

DivisionByZeroException::DivisionByZeroException(string em)
    : ExceptionSystem(em) {
  errormessage = "Division By Zero: " + errormessage;
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

DivisionByZeroException::~DivisionByZeroException() {
  // Nothing to do here, placeholder.
}
