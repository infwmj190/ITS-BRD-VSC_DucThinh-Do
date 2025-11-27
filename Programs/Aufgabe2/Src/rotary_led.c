/**
 * @file    rotary_led.c
 * @author  Duc Thinh Do
  *@date    20.11.2025  
 * @brief   Implementierung der LED-Steuerfunktionen für den Drehgeber.
 *
 *          Dieses Modul steuert folgende LEDs:
 *            - D8  bis D15  (Port D): 8-Bit-Binärausgabe des Schrittzählers
 *            - D21 (PE5): Fehleranzeige
 *            - D22 (PE6): Drehrichtung Rückwärts
 *            - D23 (PE7): Drehrichtung Vorwärts
 *
 *          Die Ansteuerung erfolgt über das BSRR-Register
 *          (Bit Set/Reset Register) der jeweiligen GPIO-Ports.
 */

#include "rotary_led.h"
#include "stm32f4xx_hal.h"
#include "rotary_calculator.h"


/**
 * @brief   Gibt den aktuellen Schrittzähler (phasencounter) als 8-Bit Wert
 *          auf den LEDs D8–D15 (Port D) aus.
 *
 *          Die unteren 8 Bits von 'phasencounter' werden angezeigt.
 *          Negative Werte werden dabei automatisch durch das Zweierkomplement
 *          korrekt dargestellt.
 *
 * @param   phasencounter   Aktueller Schrittzähler
 */
void setLEDCounter(int phasencounter) {
    int on = phasencounter & 0xFF;     // Bits, die eingeschaltet werden sollen
    int off = (~on) & 0xFF;            // Bits, die ausgeschaltet werden sollen

    // Untere 16 Bit:  1 → LED einschalten
    // Obere 16 Bit:   1 → LED ausschalten
    GPIOD->BSRR = on | (off << 16);     

    //phasencounter = -1 -> In Zweierkomplement: 1111 1111 .... 1111
    //D8–D15 werden alle angeschaltet, keine LED wird ausgeschaltet
}


/**
 * @brief   Schaltet die Fehler-LED (D21, Pin PE5) ein.
 */
void setErrorLED() {
    GPIOE->BSRR = 1 << 5;   // Pin 5 setzen → LED an
}


/**
 * @brief   Schaltet die Fehler-LED (D21, Pin PE5) aus.
 */
void clearErrorLED() {
    GPIOE->BSRR = 1 << (5 + 16);   // Oberes BSRR-Bit → Pin 5 zurücksetzen → LED aus
}


/**
 * @brief   Setzt die Drehrichtungsanzeige.
 *
 *          STATE_FORWARD   → LED D23 (PE7) an, LED D22 (PE6) aus  
 *          STATE_BACKWARDS → LED D22 (PE6) an, LED D23 (PE7) aus
 *
 *          Andere Zustände (NOCHANGE / ERROR) ändern den LED-Zustand nicht.
 *
 * @param   state   Zustand aus rotary_calculator.h
 */
void setLEDDirection(int state)
{
    switch (state) {
        case STATE_FORWARD:
            GPIOE->BSRR = (1 << 7) | (1 << (6 + 16));   // E7 an, E6 aus
            break;

        case STATE_BACKWARDS:
            GPIOE->BSRR = (1 << 6) | (1 << (7 + 16));   // E6 an, E7 aus
            break;
    }
}

//keine Reaktion bei NOCHANGE oder ERROR, damit die letzte bekannte Richtung sichtbar bleibt,
//auch wenn das Rad gerade stillsteht oder ein Fehler erkannt wurde.