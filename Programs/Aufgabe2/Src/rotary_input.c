/**
  * @file    rotary_input.c
  * @author  Duc Thinh Do
  * @date    20.11.2025
  * @brief   Modul zum Einlesen der Eingangs-Pins PF0 und PF1 (Photodioden des
  *          Drehgebers) sowie der Taste S6. Die beiden Photodioden bilden die
  *          beiden Quadratur-Signale A und B.
  */

#include <rotary_input.h>
#include <stm32f429xx.h>
#include <stm32f4xx_hal.h>

/**
 * @brief Liest die Bits PF0 und PF1 ein.
 *
 *        PF0 = Kanal A des Drehgebers  
 *        PF1 = Kanal B des Drehgebers
 *
 *        Das IDR-Register (Input Data Register) enthält die Pegel aller Pins
 *        eines Ports. Durch Maskierung mit 0x03 (Binär: 00000011) werden nur
 *        die unteren zwei Bits extrahiert.
 *
 * @return Wert zwischen 0 und 3:
 *         - 0b00 = Phase A
 *         - 0b01 = Phase D
 *         - 0b10 = Phase B
 *         - 0b11 = Phase C
 */
int readInput(void) {
    return GPIOF->IDR & 0x03;
}


/**
 * @brief Prüft, ob die Taste S6 gedrückt wurde.
 *
 *        Die Taste S6 liegt auf PF6 und ist "active low".
 *        Das bedeutet:
 *          - PF6 = High → Taste NICHT gedrückt
 *          - PF6 = Low  → Taste gedrückt
 *
 *        Daher negiert die Funktion das Ergebnis.
 *
 * @return 1 wenn Taste S6 gedrückt ist, sonst 0
 */
int buttonS6_pressed(void) {
    return !(GPIOF->IDR & (1 << 6));  // Ergebnis von GPIOF->IDR & (1 << 6) = 0 -> false, sonst true
}
