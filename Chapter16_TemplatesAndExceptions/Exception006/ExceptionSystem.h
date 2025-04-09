/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Specification for the ExceptionSystem class.
*/

#ifndef EXCEPTIONSYSTEM_H_
#define EXCEPTIONSYSTEM_H_

#include <string>

using namespace std;

class ExceptionSystem {
protected:
  string errormessage;

public:
  ExceptionSystem(string em = "");
  virtual ~ExceptionSystem();

  string message();
};

#endif /* EXCEPTIONSYSTEM_H_ */
