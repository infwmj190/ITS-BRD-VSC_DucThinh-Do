/**
  * @file   error_handling.h
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  This modules implements a simple error handling strategies
  */

#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#define SUCCESS 0
#define OVERFLOW -3
#define UNDERFLOW -4
#define DIVISION_WITH_0	-5
#define NOT_ENOUGH_OPERANDS	-6
#define OUT_OF_RANGE -7
#define UNEXPECTED_TOKEN -8
#define UNEXPECTED_ERROR -9


void errorBehandlung(int errorTyp);


#endif /* ERROR_HANDLING_H */
// EOF