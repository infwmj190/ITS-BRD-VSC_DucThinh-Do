/**
  * @file rotary_calculator.h
  * @author Duc Thinh Do 
  * @date 20.11.2025
  * @brief Header-Datei des Encodermoduls (Berechnung & Zustandsbestimmung).
  */

#ifndef ROTARY_RECHNER_H
#define ROTARY_RECHNER_H

#include <stdint.h>

/**
 * @brief Maske für die vorherige Phase der Zustandsmaschine.
 *        (Wird verwendet, um die alte Phase aus einem zusammengesetzten Wert auszulesen.)
 */
#define ORIG_PHASE_MASK 0x2

/**
 * @brief Maske für die aktuelle Phase der Zustandsmaschine.
 *        (Wird verwendet, um die neue Phase aus einem zusammengesetzten Wert auszulesen.)
 */
#define TRANS_PHASE_MASK 0x0

/**
 * @brief Zustand: Der Encoder bewegt sich in Vorwärtsrichtung.
 */
#define STATE_FORWARD 1

/**
 * @brief Zustand: Der Encoder bewegt sich in Rückwärtsrichtung.
 */
#define STATE_BACKWARDS 2

/**
 * @brief Zustand: Es gab keinen Phasenwechsel.
 *        Dieser Zustand tritt auf, wenn der Encoder stillsteht
 *        oder die gleiche Phase mehrfach hintereinander eingelesen wurde.
 */
#define STATE_NOCHANGE 3

/**
 * @brief Fehlerzustand: Ein Übergang von der vorherigen zur aktuellen Phase
 *        ist laut Phasenlogik nicht erlaubt.
 *        Dies tritt z. B. bei Signalfehlern oder zu schnellen Drehbewegungen auf.
 */
#define STATE_ERROR 4

/**
 * @brief Bestimmt anhand zweier Phasen (alt, neu) den Bewegungszustand.
 *
 * @param lastPhase  Die zuvor eingelesene Phase (A, B, C oder D als 0–3).
 * @param currPhase  Die aktuell eingelesene Phase.
 * @return           Einer der Zustände: FORWARD, BACKWARDS, NOCHANGE oder ERROR.
 */
int rotary_determineState(uint32_t lastPhase, uint32_t currPhase);

/**
 * @brief Berechnet aus Schrittzahl und Schrittwinkel den aktuellen Drehwinkel.
 *
 * @param angle         Pointer auf die Ausgabevariable für den Winkel in Grad.
 * @param steps         Anzahl der ermittelten Phasenwechsel (vorwärts positiv).
 * @param anglePerStep  Winkeländerung pro Phasenschritt (z. B. 0.3°).
 * @return              0 bei Erfolg.
 */
int rotary_getAngle(double *angle, int steps, double anglePerStep);

/**
 * @brief Berechnet die Winkelgeschwindigkeit in Grad pro Sekunde.
 *
 * @param angle         Pointer auf die Ausgabevariable für die Geschwindigkeit.
 * @param steps         Anzahl der Schritte in einem definierten Zeitfenster.
 * @param anglePerStep  Winkeländerung pro Schritt.
 * @return              0 bei Erfolg.
 */
int rotary_getSpeed(double *angle, int steps, double anglePerStep);

#endif /* ROTARY_RECHNER_H */
// EOF
