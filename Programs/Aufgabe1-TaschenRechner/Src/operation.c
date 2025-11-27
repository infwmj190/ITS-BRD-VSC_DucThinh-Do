/**
  * @file   opertaion.c
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  This modules implements a simple operation like add sub mul and div
  */

#include "operation.h"
#include "error_handling.h"
#include "stack.h"
#include <limits.h>


/**
    addiere zwei zahlen
*/
int add()
{
    int r1 = 0; 
    int r2 = 0;
    int r = pop(&r1);
    
    if(r < 0)
    {
        return r;

    }

    r = pop(&r2);

    if(r < 0)
    {
        return r;

    }

    if(r1 > INT_MAX - r2 || r1 < INT_MIN - r2)
    {
        return OUT_OF_RANGE;

    }else 
    {
        push(r1 + r2);
        return SUCCESS;
    }
    
}


/**
    subtrahiere zwei zahlen
*/
int sub()
{
    int r1 = 0; 
    int r2 = 0;
    int r = pop(&r1);

    if(r < 0)
    {
        return r;

    }

    r = pop(&r2);

    if(r < 0)
    {
        return r;
    }

    if (r1 > 0 && r2 > INT_MAX + r1 || r1 < 0 && r2 < INT_MIN + r1 ) {
        return OUT_OF_RANGE;
    
    }else {
        push(r2 - r1 );
        return SUCCESS;
    
    }

}

/**
    multipliziere zwei zahlen
    überprüft ÜBERLAUF
*/
int mul()
{
    int r1 = 0; 
    int r2 = 0;

    int r = pop(&r1);
    if(r < 0)
    {
        return r;

    }

    r = pop(&r2);
    if(r < 0)
    {
        return r;

    }
    
    if (r1 == INT_MIN && r2 == -1)   // Spezialfall: +2147483648 → zu groß → Fehler
    return OUT_OF_RANGE;

    if (r1 != 0 && (r2 > INT_MAX / r1 || r2 < INT_MIN / r1))

    push (r1 * r2);  
    return SUCCESS;
    

}

/**
    dividiere zwei zahlen
    überprüft DIVISION bei 0 und ÜBERLAUF!
*/
int div()
{
    int r1 = 0; 
    int r2 = 0;
    int r = pop(&r1);

    if(r < 0)
    {
        return r;
    }


    r = pop(&r2);
    if(r < 0)
    {
        return r;
    }


    if (r1 == 0) {
        return DIVISION_WITH_0;
    
    }

    if (r2 == INT_MIN && r1 == -1) 
    {   return OUT_OF_RANGE;  

    }else 
    {
        push(r2 / r1); 
        return SUCCESS;
    
    }

}

