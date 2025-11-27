/**
  * @file rotary_display.h
  * @author Duc Thinh Do  
  * @date 20.11.2025
  * @brief Header-Datei des Anzeigenmodules für den Drehgeber.
  *
  * Dieses Modul ist verantwortlich für die Ausgabe von Winkel und
  * Winkelgeschwindigkeit auf dem LCD-Display. Es enthält die Funktionen
  * zur Initialisierung des Displays sowie zur regelmäßigen Aktualisierung
  * der angezeigten Werte.
  */

#ifndef ROTARY_DISPLAY_H
#define ROTARY_DISPLAY_H

#include <stdbool.h>

/*
 ****************************************************************************************
 * @brief   Initialisiert das LCD-Display für die Drehgeberanzeige.
 *
 *          Diese Funktion richtet das Display ein, setzt die Helligkeit
 *          (abhängig von der verwendeten GUI) und gibt statische Texte wie
 *          „Winkel:“ und „Geschwindigkeit:“ einmalig aus.
 *
 * @return  void
 ****************************************************************************************
 */
void initDisplay(void);

/*
 ****************************************************************************************
 * @brief   Aktualisiert die Anzeige von Winkel und Winkelgeschwindigkeit.
 *
 *          Aus Performancegründen (langsames LCD) gibt diese Funktion bei
 *          jedem Aufruf nur ein Zeichen pro Messwert aus. Dadurch wird die
 *          Super-Loop-Laufzeit reduziert und die Maximalgeschwindigkeit des
 *          Drehgebers, die das System noch zuverlässig erfassen kann,
 *          erheblich erhöht.
 *
 * @param angle        Der berechnete Winkel in Grad.
 * @param anglePerSec  Die berechnete Winkelgeschwindigkeit in Grad pro Sekunde.
 *
 * @return  void
 ****************************************************************************************
 */
void updateDisplay(double angle, double anglePerSec);

#endif
// EOF
