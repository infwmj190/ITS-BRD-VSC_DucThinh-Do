/**
  * @file   error_handling.c
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  This modules implements a simple error handling strategies
  */

#include "error_handling.h"
#include "display.h"


void errorBehandlung(int errorTyp)
  {
    char *errorMsg;
    switch (errorTyp) {
      case DIVISION_WITH_0:
        errorMsg = "Division durch Null\nunmoeglich!";
        break;
      case UNDERFLOW:
        errorMsg = "Stack ist Leer !";
        break;
      case OVERFLOW:
        errorMsg = "Stack ist voll !";
        break;
      case NOT_ENOUGH_OPERANDS:
        errorMsg = "nicht reichende operenden!";
        break;
      case OUT_OF_RANGE:
        errorMsg = "MIN / MAX limits\nueberschritten!";
        break;
      case UNEXPECTED_TOKEN:
        errorMsg = "unbekannte Eingabe!";
        break;
      default:
        errorMsg = "Fehler konnte nicht\nfestgestellt werden!";
    }
    setErrMode();
    printStdout(errorMsg);
  }


