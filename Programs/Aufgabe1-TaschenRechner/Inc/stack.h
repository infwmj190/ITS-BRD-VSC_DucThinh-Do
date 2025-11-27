/**
  * @file   stack.c
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  This modules implements a simple Stack with array of 100 
            and we have several function to manipulate the Stack
  */



#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#define MAX_SIZE_STACK 100




/**
    pusht einen Zahl in den Stack
*/
int push(int zahl);

/**
    popt die letzte zahl in der stack
*/
int pop(int *val);

/**
    drückt aus oberste Stack 

*/
int printTop(void);

/**
    drückt alles im Stack 

*/
int printAll(void);

/**
    löscht alles im stack
*/
int deleteAll(void);

/**
    vertauscht die position oberste zwei zahlen im stack
*/
int swap(void);

/**
    kopiert oberste zahl im stack und tut sie im nächsten stack zelle
*/
int doppeln(void);

/**
    fragt ob stack leer ist
*/
bool isEmpty(void);


/**
   fragt ob stack voll ist
*/
bool isFull(void);

/**
   gibt zurück wo der Pointer gerade steht.
*/
int getCurrentStack();

/**
   gibt der oberster Wert ohne den zu verändern!
*/
int peek(int *val, int index);



#endif /* STACK_H */
// EOF