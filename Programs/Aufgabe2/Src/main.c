/**
 * @file    main.c
 * @author  Duc Thinh Do
 * @date    20.11.2025
 * @brief   Hauptprogramm für die Drehgeber-Polling-Aufgabe.
 *
 *          Das Programm liest die beiden Quadratureingänge PF0 und PF1 per Polling ein,
 *          bestimmt daraus die Bewegungsrichtung, berechnet Winkel und
 *          Winkelgeschwindigkeit und gibt diese Informationen auf LEDs und LCD aus.
 *
 *          Zusätzlich wird der Fehlerfall überwacht und per LED signalisiert.
 */

#include "init.h"               // Initialisiert das ITS-Board
#include "rotary_calculator.h"  // Zustandsautomat (FSM) für Phasenübergänge
#include "rotary_display.h"     // Displayausgabe
#include "rotary_input.h"       // Einlesen von PF0/PF1 + S6
#include "rotary_states.h"      // State-Konstanten (FORWARD, BACKWARDS, ...)
#include "timer.h"              // Zeitmessung per Hardwaretimer
#include <stdint.h>
#include <timer.h>
#include <lcd.h>
#include "rotary_led.h"         // LED-Ausgabe D8–D15, Fehler, Richtung

#define PHASE_MASK 0x3
#define PHASE_WIDTH 2

// Einheitenumrechnung für Zeitmessung
#define TICKS_PER_SECOND 90000000.0        // 90 MHz Timer

// Encoder hat 1200 Phasenwechsel pro Umdrehung, ein Schritt entspricht also 360 / 1200 = 0.3°
#define MAX_DEGREES 1200.0
#define DEGREE_PER_MOVEMENT (360.0 / MAX_DEGREES)


/**
 * @brief Main-Funktion (Super-Loop / Direct Digital Control)
 */
int main(void) {

    uint32_t lastUpdate = 0;     // Zeitstempel des letzten Geschwindigkeits-Updates
    double angle = 0.0;          // Aktueller Winkel in Grad
    double lastAngle = 0.0;      // Winkel beim letzten Update (zur Berechnung von anglePerSec)
    double anglePerSec = 0;      // Winkelgeschwindigkeit in Grad/s
    int phaseCounter = 0;        // Zählt Vorwärts-/Rückwärtsschritte
    bool errorState = false;     // Merkt, ob ein Fehlerzustand aktiv ist

    // Hardware initialisieren
    initITSboard();
    initDisplay();
    initTimer();

    uint32_t lastPhase = readInput(); //Liest die Bits PF0 und PF1 ein

    while (1) {
        uint32_t phase = readInput();       // aktuelle Phase A/B/C/D
        uint32_t timestamp = getTimeStamp(); // aktueller Timerwert

        if (errorState) {
            if (buttonS6_pressed()) {       // Fehlerquittierung über S6
                lastPhase = readInput();    // neue Startphase setzen
                clearErrorLED();            // Fehler-LED löschen
                phaseCounter = 0;           // Zähler zurücksetzen
                errorState = false;         // Fehlerzustand beenden
            }
            continue;   // Rest der Loop überspringen
			            // Wenn ein Fehler aktiv ist, wird es gar nichts weiter gmemacht, bis S6 gedrückt wird.
        }

        // Bewegungszustand bestimmen (vorwärts, rückwärts, keine Änderung, Fehler)
        int state = rotary_determineState(lastPhase, phase);
        lastPhase = phase;

        // Ticks -> Sekunden für Winkelgeschwindigkeit
        uint32_t timeSinceUpdate = timestamp - lastUpdate;
        double timeInSeconds = timeSinceUpdate / TICKS_PER_SECOND;

		// Die Geschwindigkeit wird aktualisiert
        if ((timeInSeconds >= 0.25 && state != STATE_NOCHANGE) ||  // nach 0,25s und es Bewegung gibt
            timeInSeconds > 0.5) {                                 // oder spätestens nach 0,5s

            double angleDiff = angle - lastAngle;
            anglePerSec = angleDiff / timeInSeconds;

            lastAngle = angle;
            lastUpdate = timestamp;
        }

        // Bewegungszustand verarbeiten
        switch (state) {
            case STATE_FORWARD:
                phaseCounter++;   // vorwärts
                break;
            case STATE_BACKWARDS:
                phaseCounter--;   // rückwärts
                break;
            case STATE_NOCHANGE:
                // keine Änderung
                break;
            case STATE_ERROR:
                setErrorLED();    // Fehler signalisieren
                errorState = true;
                break;
        }

        // Winkel berechnen
        angle = phaseCounter * DEGREE_PER_MOVEMENT;

        // Ausgabe (nur wenn kein Fehler)
        updateDisplay(angle, anglePerSec);   // zeichenweise Display-Ausgabe
        setLEDCounter(phaseCounter);         // 8-Bit-Schrittzähler auf LEDs D8-D15
        setLEDDirection(state);              // Richtung auf D22/D23 anzeigen
    }
}

// EOF
