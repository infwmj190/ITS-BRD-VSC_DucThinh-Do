/**
  * @file    rotary_calculator.c
  * @author  Duc Thinh Do
  * @date    20.11.2025
  * @brief   Implementierung der Zustandslogik (Finite State Machine) für
  *          den Drehgeber. Bestimmt aus zwei aufeinanderfolgenden Phasen
  *          die Bewegungsrichtung oder einen Fehlerzustand.
  */

#include "rotary_calculator.h"
#include <stdint.h>
#include <stm32f4xx_hal.h>
#include "rotary_states.h"

/**
 * @brief Makro, um aus vorheriger und aktueller Phase einen gemeinsamen
 *        Übergangswert zu berechnen.
 *
 *        Wird in dieser Implementierung nicht direkt genutzt, zeigt aber,
 *        wie man aus zwei Phasen ein zusammengesetztes Bitmuster bilden könnte.
 *
 *        p1 = vorherige Phase (lastPhase)
 *        p2 = aktuelle Phase (currPhase)
 *
 *        ORIG_PHASE_MASK und TRANS_PHASE_MASK stammen aus dem Header.
 */
#define PHASE_TRANSF(p1, p2) ((p1 << ORIG_PHASE_MASK) | (p2 << TRANS_PHASE_MASK))


/**
 * @brief Bestimmt den Bewegungszustand des Drehgebers anhand der Phasenfolge.
 *
 * Diese Funktion implementiert eine Finite State Machine (FSM) über eine
 * 4x4-Übergangsmatrix. Jeder Eintrag der Matrix beschreibt, welcher Zustand
 * (vorwärts, rückwärts, keine Änderung, Fehler) entsteht, wenn sich die Phase
 * von lastPhase zu currPhase ändert.
 *
 * Die Phasen werden typischerweise wie folgt kodiert:
 *   0 -> Phase A
 *   1 -> Phase B
 *   2 -> Phase C
 *   3 -> Phase D
 *
 * @param lastPhase  Die Phase, die beim letzten Einlesen festgestellt wurde
 *                   (Wert von 0 bis 3).
 * @param currPhase  Die aktuell eingelesene Phase (ebenfalls 0 bis 3).
 *
 * @return           Einer der Zustände:
 *                   STATE_FORWARD   (Vorwärtsbewegung)
 *                   STATE_BACKWARDS (Rückwärtsbewegung)
 *                   STATE_NOCHANGE  (keine Änderung)
 *                   STATE_ERROR     (ungültiger Übergang / Fehler)
 */
int rotary_determineState(uint32_t lastPhase, uint32_t currPhase) {

  /* Übergangsmatrix der FSM.
   * Zeilenindex  = lastPhase  (vorherige Phase)
   * Spaltenindex = currPhase  (aktuelle Phase)
   *
   * Beispiel: matrix[0][1] beschreibt den Übergang von Phase A nach B.
   */
  const int matrix[4][4] =
  {
    /* von A (0) nach:    A              B               C               D          */
    { STATE_NOCHANGE,  STATE_FORWARD,   STATE_BACKWARDS, STATE_ERROR     },

    /* von B (1) nach:    A              B               C               D          */
    { STATE_BACKWARDS, STATE_NOCHANGE,  STATE_ERROR,     STATE_FORWARD   },

    /* von C (2) nach:    A              B               C               D          */
    { STATE_FORWARD,   STATE_ERROR,     STATE_NOCHANGE,  STATE_BACKWARDS },

    /* von D (3) nach:    A              B               C               D          */
    { STATE_ERROR,     STATE_BACKWARDS, STATE_FORWARD,   STATE_NOCHANGE  },
  };

  /* Auswahl des passenden Eintrags in der Matrix:
   * lastPhase = Zeilenindex
   * currPhase = Spaltenindex
   */
  return matrix[lastPhase][currPhase];
}

// EOF
