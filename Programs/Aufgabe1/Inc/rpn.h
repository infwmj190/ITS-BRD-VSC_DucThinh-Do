#ifndef RPN_H
#define RPN_H

#include "stack.h"

/**
 * @file rpn.h
 * @brief Funktionen für den Reverse Polish Notation (RPN) Taschenrechner.
 *
 * Dieses Modul implementiert die Operationen des RPN-Rechners auf einem Stack.
 * Fehler werden über Rückgabewerte (negative Zahlen) gemeldet.
 */

/** Fehlercodes für RPN-Operationen */
#define ERR_DIV_ZERO    -3
#define ERR_OVERFLOW    -4
#define ERR_UNKNOWN     -5

/**
 * @brief Addiert die beiden obersten Werte des Stacks und legt das Ergebnis wieder auf den Stack.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Underflow oder Overflow)
 */
int rpn_add(Stack *s);

/**
 * @brief Subtrahiert den obersten Wert vom zweitobersten Wert und legt das Ergebnis wieder auf den Stack.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Underflow oder Overflow)
 */
int rpn_sub(Stack *s);

/**
 * @brief Multipliziert die beiden obersten Werte des Stacks und legt das Ergebnis wieder auf den Stack.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Underflow oder Overflow)
 */
int rpn_mul(Stack *s);

/**
 * @brief Teilt den zweitobersten Wert durch den obersten Wert des Stacks (ganzzahlige Division)
 *        und legt das Ergebnis wieder auf den Stack.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Division durch 0, Stack Underflow)
 */
int rpn_div(Stack *s);

/**
 * @brief Gibt den obersten Wert des Stacks aus, ohne ihn zu entfernen.
 *
 * @param[in] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Underflow)
 */
int rpn_print_top(Stack *s);

/**
 * @brief Gibt den gesamten Stack aus, ohne ihn zu verändern.
 *
 * @param[in] s Zeiger auf den Stack.
 * @return 0 bei Erfolg
 */
int rpn_print_stack(const Stack *s);

/**
 * @brief Löscht alle Einträge des Stacks.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0
 */
int rpn_clear(Stack *s);

/**
 * @brief Dupliziert den obersten Eintrag des Stacks.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Overflow oder Underflow)
 */
int rpn_dup(Stack *s);

/**
 * @brief Vertauscht die Reihenfolge der beiden obersten Einträge des Stacks.
 *
 * @param[in,out] s Zeiger auf den Stack.
 * @return 0 bei Erfolg, <0 bei Fehler (z.B. Stack Underflow)
 */
int rpn_swap(Stack *s);

#endif // RPN_H
