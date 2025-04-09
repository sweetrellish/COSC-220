/*
 Author: Don Spickler
 Creation Date: 1/27/2022
 Last Update: 1/27/2022
 */

#include "ExceptionSystem.h"

/*
 Description: Constructor
 Parameters: em - the error message.
 Return: None
 */

ExceptionSystem::ExceptionSystem(string em) { errormessage = em; }

/*
 Description: Destructor
 Parameters: None
 Return: None
 */

ExceptionSystem::~ExceptionSystem() {
  // Nothing to do here, placeholder.
}

/*
 Description: Returns the currently saved error message.
 Parameters: None
 Return: Error message
 */

string ExceptionSystem::message() { return errormessage; }
