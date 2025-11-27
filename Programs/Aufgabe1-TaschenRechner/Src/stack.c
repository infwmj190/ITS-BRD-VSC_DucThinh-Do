/**
  * @file   stack.c
  * @author Duc Thinh Do 
  * @date   21.10.2025
  * @brief  Implementierung eines einfachen Stacks (Kellerspeicher) 
  *         mit 100 Elementen und Funktionen zum Manipulieren.
  */

#include "stack.h"
#include "error_handling.h"
#include "display.h"

// Statisches Array als Stack-Speicher (max. 100 Elemente)
static int stack[MAX_SIZE_STACK];

// Index / Zeiger auf das nächste freie Stack-Element
// entspricht gleichzeitig der Anzahl der Elemente im Stack
static int currentStack = 0;

// Legt eine Zahl oben auf den Stack
int push(int zahl)
{
    if (isFull())             
    {
        return OUT_OF_RANGE;          // Fehler: Stack ist voll
    }
    else 
    {
        stack[currentStack] = zahl;  // Zahl speichern
        currentStack++;              // Zeiger erhöhen
        return SUCCESS;              // Erfolg melden
    }
}

// Holt die oberste Zahl vom Stack (mit Rückgabe über Pointer)
int pop(int *val)
{
    if (isEmpty())            
    {
        return UNDERFLOW;             // Fehler: Stack ist leer
    }
    else 
    {
        --currentStack;               // Eine Position nach oben gehen
        *val = stack[currentStack];   // Wert zurückgeben
        return SUCCESS;
    }
}

// Gibt die oberste Zahl aus, ohne sie zu verändern
int printTop(void)
{
    if (isEmpty())
    {
        return UNDERFLOW;     // Fehler: Stack ist leer
    }
    else
    {
        int stackTop = 0;
        peek(&stackTop, getCurrentStack() - 1);  // oberstes Element ansehen
        printNr(stackTop);                       // Zahl ausgeben
        return SUCCESS;
    }
}

// Gibt den gesamten Stack aus (von oben nach unten)
int printAll(void)
{
    if (isEmpty())
    {
        return UNDERFLOW;
    }

    for (int i = 0, x = 1; i < getCurrentStack(); i++, x++)
    {
        int value2 = 0;
        peek(&value2, getCurrentStack() - x);  // Werte rückwärts ansehen
        printNr(value2);                       // Ausgeben
    }

    return SUCCESS;
}

// Vertauscht die zwei obersten Werte auf dem Stack
int swap(void)
{
    if (currentStack < 2)     // Mindestens zwei Werte nötig
    {
        return NOT_ENOUGH_OPERANDS;
    }
    else 
    {
        int z1 = 0;
        int z2 = 0;
        pop(&z1);      // oberster Wert
        pop(&z2);      // zweiter Wert
        push(z1);      // tauschen
        push(z2);
        return SUCCESS;
    }
}

// Dupliziert die oberste Zahl (top → push top)
int doppeln(void)
{
    if (isEmpty())
    {
        return UNDERFLOW;
    }
    else 
    {
        int value = 0;
        peek(&value, getCurrentStack() - 1); // oberste Zahl ansehen
        push(value);                         // Kopie auf den Stack legen
        return SUCCESS;
    }
}

// Löscht den gesamten Stack
int deleteAll(void)
{
    currentStack = 0;      // Zeiger auf Anfang setzen
    return SUCCESS;
}

// Prüft, ob Stack leer ist
bool isEmpty(void)
{
    return currentStack == 0;
}

// Prüft, ob Stack voll ist
bool isFull(void)
{
    return currentStack == MAX_SIZE_STACK;
}

// Gibt die Anzahl der Elemente im Stack zurück
int getCurrentStack(void)
{
    return currentStack;
}

// Liest einen Wert an bestimmter Position (ohne zu löschen)
int peek(int *val, int index)
{
    if (isEmpty())
    {
        return UNDERFLOW;  // Stack leer → Fehler
    }
    if (index < currentStack)        // Index gültig?
    {
        *val = stack[index];         // Wert in *val speichern
        return SUCCESS;
    }

    return OVERFLOW;                 // Index ungültig
}
