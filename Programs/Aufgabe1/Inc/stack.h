#ifndef STACK_H
#define STACK_H

/** Fehlercodes für Stack-Operationen */

/* POSIX-Weg → Rückgabe negativer Zahlen für Fehler.
Funktionen geben 0 bei Erfolg, negative Zahl bei Fehler zurück.
Ergebnisse werden über Call-by-Reference zurückgegeben*/

#define ERR_STACK_OVERFLOW   -1
#define ERR_STACK_UNDERFLOW  -2
#define ERR_DIV_ZERO         -3
#define ERR_OVERFLOW         -4

/** Maximale Größe des Stacks */
#define STACK_SIZE 32

/** Stack-Datenstruktur */
typedef struct {
    int data[STACK_SIZE];  /**< Array zur Speicherung der Zahlen */
    int top;               /**< Index des obersten Elements im Stack */
} Stack;

/**
 * @brief     Initialisiert den Stack.
 *
 * @param[in,out] s  Zeiger auf den Stack, der initialisiert wird.
 *
 * @return    void
 *
 * @note      Muss einmal vor allen anderen Stack-Operationen aufgerufen werden.
 */
void stack_init(Stack *s);

/**
 * @brief      Legt eine Zahl auf den Stack.
 *
 * @param[in,out] s      Zeiger auf den Stack.
 * @param[in]     value  Die Zahl, die auf den Stack gelegt werden soll.
 *
 * @return     0 bei Erfolg, <0 bei Fehler.
 * @retval     0                 Erfolgreich
 * @retval     ERR_STACK_OVERFLOW Stack ist voll
 *
 * @note       Fehlercodes sind in errors.h definiert.
 */
int stack_push(Stack *s, int value);

/**
 * @brief      Entfernt die oberste Zahl vom Stack.
 *
 * @param[in,out] s      Zeiger auf den Stack.
 * @param[out]    value  Zeiger zur Speicherung der entfernten Zahl.
 *
 * @return     0 bei Erfolg, <0 bei Fehler.
 * @retval     0                 Erfolgreich
 * @retval     ERR_STACK_UNDERFLOW Stack leer
 */
int stack_pop(Stack *s, int *value);

/**
 * @brief      Gibt die oberste Zahl des Stacks zurück, ohne sie zu entfernen.
 *
 * @param[in]  s      Zeiger auf den Stack.
 * @param[out] value  Zeiger zur Speicherung der obersten Zahl.
 *
 * @return     0 bei Erfolg, <0 bei Fehler.
 * @retval     0                 Erfolgreich
 * @retval     ERR_STACK_UNDERFLOW Stack leer
 */
int stack_peek(const Stack *s, int *value);

/**
 * @brief      Dupliziert das oberste Element des Stacks.
 *
 * @param[in,out] s  Zeiger auf den Stack.
 *
 * @return     0 bei Erfolg, <0 bei Fehler.
 * @retval     0                 Erfolgreich
 * @retval     ERR_STACK_OVERFLOW Stack ist voll
 */
int stack_dup(Stack *s);

/**
 * @brief      Vertauscht die beiden obersten Elemente des Stacks.
 *
 * @param[in,out] s  Zeiger auf den Stack.
 *
 * @return     0 bei Erfolg, <0 bei Fehler.
 * @retval     0                 Erfolgreich
 * @retval     ERR_STACK_UNDERFLOW Stack hat weniger als zwei Elemente
 */
int stack_swap(Stack *s);

/**
 * @brief     Löscht alle Elemente des Stacks.
 *
 * @param[in,out] s  Zeiger auf den Stack.
 *
 * @return    void
 */
void stack_clear(Stack *s);

/**
 * @brief      Gibt den gesamten Stack auf dem Terminal/Display aus.
 *
 * @param[in] s  Zeiger auf den Stack.
 *
 * @return    void
 *
 * @note      Fehlerbehandlung erfolgt nur intern (z.B. leeren Stack anzeigen).
 */
void stack_print(const Stack *s);

#endif // STACK_H
