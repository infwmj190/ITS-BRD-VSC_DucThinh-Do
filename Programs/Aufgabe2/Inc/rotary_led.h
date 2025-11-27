/**
  * @file rotary_led.h
  * @author Duc Thinh Do 
  * @date 20.11.2025
  * @brief Header-Datei des LED-Ausgabemoduls für den Drehgeber.
  *
  * Dieses Modul steuert alle LEDs, die im Rahmen der Drehgeberaufgabe benötigt werden.
  * Dazu gehören:
  *   - LED D21: Fehleranzeige
  *   - LED D22: Drehrichtung Rückwärts
  *   - LED D23: Drehrichtung Vorwärts
  *   - LED D8–D15: Binäre Ausgabe des Phasen-/Schrittzählers
  *
  * Das Modul kapselt alle BSRR-Zugriffe (Bit Set/Reset Register) des Mikrocontrollers,
  * sodass das Hauptprogramm nicht direkt mit GPIO-Details arbeiten muss.
  */

#ifndef ROTARY_LED_H
#define ROTARY_LED_H

#include <stdbool.h>

/*
 ****************************************************************************************
 * @brief   Schaltet die Fehler-LED (D21) ein.
 *
 *          Diese LED leuchtet, wenn ein ungültiger Phasenübergang erkannt wurde
 *          (z. B. durch zu schnelles Drehen oder fehlerhafte Signalfolge).
 *
 * @return  void
 ****************************************************************************************
 */
void setErrorLED(void);

/*
 ****************************************************************************************
 * @brief   Löscht die Fehler-LED (D21).
 *
 *          Diese Funktion wird aufgerufen, wenn der Benutzer die Taste S6 drückt,
 *          um den Fehlerzustand zurückzusetzen.
 *
 * @return  void
 ****************************************************************************************
 */
void clearErrorLED(void);

/*
 ****************************************************************************************
 * @brief   Zeigt den aktuellen Schritt-/Phasenzähler auf den LEDs D8–D15 (Port D).
 *
 *          Die unteren 8 Bit von 'phasencounter' werden direkt als Binärwert
 *          auf die LEDs D8 bis D15 ausgegeben. Negative Werte werden durch das
 *          Zweierkomplement korrekt dargestellt.
 *
 * @param   phasencounter   Aktueller Phasen-/Schrittzähler des Encoders
 *
 * @return  void
 ****************************************************************************************
 */
void setLEDCounter(int phasencounter);

/*
 ****************************************************************************************
 * @brief   Zeigt die Drehrichtung an.
 *
 *          Die Zuordnung lautet:
 *            - STATE_FORWARD   → LED D23 an, LED D22 aus
 *            - STATE_BACKWARDS → LED D22 an, LED D23 aus
 *
 *          Andere Zustände (NOCHANGE, ERROR) verändern die Anzeige nicht.
 *
 * @param   state   Zustand der Zustandsmaschine (FSM):
 *                  STATE_FORWARD, STATE_BACKWARDS, STATE_NOCHANGE, STATE_ERROR
 *
 * @return  void
 ****************************************************************************************
 */
void setLEDDirection(int state);

#endif
// EOF
