/**
  * @file rotary_input.h
  * @author Duc Thinh Do  
  * @date 20.11.2025
  * @brief Header-Datei des Eingabemoduls für den Drehgeber.
  *
  * Dieses Modul stellt Definitionen der Encodersignale (Phasen A–D) bereit
  * sowie Funktionen zum Einlesen der beiden Photodioden (Kanal A = PF0,
  * Kanal B = PF1) und der Taste S6.
  */

#ifndef ROTARY_INPUT_H
#define ROTARY_INPUT_H

/**
 * @brief Phase A: PF1 = 0, PF0 = 0
 *
 * Diese Bitkombination entspricht dem Zustand,
 * wenn beide Eingangspins LOW sind.
 */
#define PHASE_A 0x00

/**
 * @brief Phase B: PF1 = 1, PF0 = 0
 *
 * Photodiode B HIGH, Photodiode A LOW.
 */
#define PHASE_B 0x10

/**
 * @brief Phase C: PF1 = 1, PF0 = 1
 *
 * Beide Photodioden HIGH.
 */
#define PHASE_C 0x11

/**
 * @brief Phase D: PF1 = 0, PF0 = 1
 *
 * Photodiode A HIGH, Photodiode B LOW.
 */
#define PHASE_D 0x01


/*
 ****************************************************************************************
 * @brief   Initialisiert den Eingabebereich für den Drehgeber.
 *
 *          In dieser Version sind die Eingänge bereits durch initITSboard() gesetzt,
 *          daher ist die Funktion möglicherweise leer oder optional. Sie dient der
 *          Strukturierung des Projekts.
 *
 * @return  void 
 ****************************************************************************************
 */
void initInput(void);


/*
 ****************************************************************************************
 * @brief   Liest die Pins PF0 und PF1 ein und liefert deren Zustand zurück.
 *
 *          Die beiden Photodioden des Drehgebers liegen an:
 *            PF0 → Kanal A
 *            PF1 → Kanal B
 *
 *          Die Funktion gibt nur die unteren zwei Bits zurück,
 *          sodass ein Wert zwischen 0 und 3 entsteht.
 *
 *          Dieser Wert wird später der Zustandsmaschine (FSM) übergeben.
 *
 * @return  Wert der Phase (0 bis 3)
 ****************************************************************************************
 */
int readInput(void);


/**
 * @brief Prüft, ob die Taste S6 gedrückt ist.
 *
 *        S6 ist aktiv LOW, d. h.:
 *          - Pin HIGH  → Taste nicht gedrückt
 *          - Pin LOW   → Taste gedrückt
 *
 * @return 1 wenn Taste S6 gedrückt ist, sonst 0
 */
int buttonS6_pressed(void);

#endif 
// EOF
