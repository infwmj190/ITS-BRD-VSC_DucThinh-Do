/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"
#include "display.h"
#include "scanner.h"
#include "superLoop.h"



int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	initDisplay();
	//Program loop
	while (1) {
		T_token token = nextToken(); // liest der nächten Token
		char input = token.tok; // wir brauchen den tok von token
		switchInput(input, token.val); // in superLoop.c geschrieben. Token Auswertung UND Fehrlern handlung.
		
	
	}

	
	// Test in Endlosschleife
	while(1) {
		HAL_Delay(10000);
	}
}

// EOF
