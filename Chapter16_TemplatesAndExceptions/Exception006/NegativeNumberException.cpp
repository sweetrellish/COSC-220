/*
 Author: Don Spickler
 Creation Date: 1/27/2022
 Last Update: 1/27/2022
 */

#include "NegativeNumberException.h"

/*
 Description: Constructor
 Parameters: em - the error message.
 Return: None
 */

NegativeNumberException::NegativeNumberException(string em)
    : ExceptionSystem(em) {
  errormessage = "Negative Number: " + errormessage;
}

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

NegativeNumberException::~NegativeNumberException() {
  // Nothing to do here, placeholder.
}
