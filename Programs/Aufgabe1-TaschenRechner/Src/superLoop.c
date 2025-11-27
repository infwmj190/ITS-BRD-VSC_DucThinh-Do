/**
  * @file   superLoop.c
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  This modules implements a simple switch case for token input
  */

#include "superLoop.h"
#include "operation.h"
#include "stack.h"
#include "error_handling.h"
#include "display.h"

static int result = 0;

int switchInput(char input, int tokVal)
{
    switch (input) 
	{
		case 'n':
			result = push(tokVal);
			break;

		case '+':
			result = add();
			break;

		case '-':
			result = sub();
			break;

		case '/':
			result = div();
			break;

		case '*':
			result = mul();
			break;

		case 'p':   // klein
			result = printTop();
			break;

		case 'P':  // groß
			result = printAll();
			break;

		case 'C':
			result = deleteAll();
			clearStdout();
			break;

		case 'r':
			result = swap();
			break;

		case 'd':
			result = doppeln();
			break;

		case 'U':
			result = UNEXPECTED_TOKEN;
			break;

		case 'O':
			result = OVERFLOW;
			break;

		default:
			result = UNEXPECTED_ERROR;
					break;
			
	}
	if(result < 0)
	{
		errorBehandlung(result);
	}


}