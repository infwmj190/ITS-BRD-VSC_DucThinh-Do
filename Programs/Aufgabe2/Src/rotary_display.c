/**
 * @file    rotary_display.c
 * @author  Duc Thinh Do
 * @date    20.11.2025
 * @brief   Implementierung des Display-Moduls zur Anzeige von Winkel und
 *          Winkelgeschwindigkeit eines Drehgebers.
 *
 *          Zur Optimierung der Super-Loop-Laufzeit wird das LCD-Display nicht
 *          vollständig in einem Durchlauf aktualisiert. Stattdessen wird pro
 *          Durchlauf nur ein einziges Zeichen ausgegeben, was die maximale
 *          erfassbare Drehgeschwindigkeit deutlich erhöht.
 */

#include "rotary_display.h"
#include "LCD_GUI.h"
#include "lcd.h"
#include <stdio.h>

//Das sind die Zeilen, die einmalig ausgegeben werden.  
//Diese Texte ändern sich nie – nur die Werte, die später an der richtigen Position eingetragen werden.
#define ANGLE_TXT "Winkel          :  0.0          Grad"
#define SPEED_TXT "Geschwindigkeit :  0.0          Grad/s"

#define YPOS_MIDDLE (19 / 2)
#define XPOS_ANGLE_TXT  2
#define XPOS_ANGLE_VAL 19
#define XPOS_SPEED_TXT  2
#define XPOS_SPEED_VAL 19
#define YPOS_ANGLE_TXT (YPOS_MIDDLE - 2)
#define YPOS_SPEED_TXT (YPOS_MIDDLE + 2)

//BUF_SIZE = 10: snprintf darf maximal 9 Zeichen + Nullterminator schreiben
#define BUF_SIZE 10


// Jedes Zeichen wird verglichen
// Nur wenn es sich geändert hat, wird es wirklich aufs LCD geschrieben.

/* Puffer für neuen und alten Winkeltext */
char buf_angle[BUF_SIZE], buf_angle_old[BUF_SIZE];

/* Puffer für neue und alte Geschwindigkeit */
char buf_speed[BUF_SIZE], buf_speed_old[BUF_SIZE];

/* Index für zeichenweise Ausgabe */
int idx = 0;


/**
 * @brief Initialisiert das LCD-Display und gibt die statischen Texte aus.
 */
void initDisplay(void) {
    GUI_init(DEFAULT_BRIGHTNESS);

    /* Statische Anzeigezeilen einmalig zeichnen */
    lcdGotoXY(XPOS_ANGLE_TXT, YPOS_ANGLE_TXT);
    lcdPrintS(ANGLE_TXT);

    lcdGotoXY(XPOS_SPEED_TXT, YPOS_SPEED_TXT);
    lcdPrintS(SPEED_TXT);
}


/**
 * @brief Aktualisiert die Anzeige von Winkel und Geschwindigkeit.
 *
 *        Um die Super-Loop-Laufzeit zu optimieren, wird bei jedem Aufruf nur
 *        ein Zeichen aktualisiert. Der gesamte Text wird in Puffer geschrieben,
 *        und anschließend wird an Position 'idx' überprüft, ob sich dieses
 *        Zeichen im Vergleich zur letzten Ausgabe geändert hat.
 *
 * @param angle        Aktueller Winkel in Grad.
 * @param anglePerSec  Aktuelle Winkelgeschwindigkeit in Grad pro Sekunde.
 */
void updateDisplay(double angle, double anglePerSec) {

    /* Bei idx == 0 wird der komplette neue Text in die Puffer geschrieben */
    if (idx == 0) {
        snprintf(buf_angle, BUF_SIZE, "%9.1f", angle); //sichere Variante von printf, die in einen Buffer (char-Array) schreibt.
        snprintf(buf_speed, BUF_SIZE, "%9.1f", anglePerSec);
    }

    /* Winkelanzeige aktualisieren – nur wenn sich das Zeichen verändert hat */
    if (buf_angle[idx] != buf_angle_old[idx]) {
        lcdGotoXY(XPOS_ANGLE_VAL + idx, YPOS_ANGLE_TXT);
        lcdPrintC(buf_angle[idx]);
        buf_angle_old[idx] = buf_angle[idx];
    }

    /* Geschwindigkeitsanzeige aktualisieren – nur wenn sich das Zeichen verändert hat */
    if (buf_speed[idx] != buf_speed_old[idx]) {
        lcdGotoXY(XPOS_SPEED_VAL + idx, YPOS_SPEED_TXT);
        lcdPrintC(buf_speed[idx]);
        buf_speed_old[idx] = buf_speed[idx];
    }

    /* Index erhöhen → nächstes Zeichen im nächsten Loop verarbeiten */
    ++idx;

    /* Wenn das Ende erreicht ist, wieder bei 0 beginnen */
    if (idx == BUF_SIZE - 1) {
        idx = 0;
    }
}