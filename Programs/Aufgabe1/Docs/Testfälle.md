# Testfälle für RPN-Rechner

## Normale Operationen

| Eingabe | Erwartete Ausgabe | Zweck |
|----------|-----------------|-------|
| 5 ENTER 3 + p | 8 | Addition |
| 10 ENTER 2 - p | 8 | Subtraktion |
| 2 ENTER 4 * p | 8 | Multiplikation |
| 8 ENTER 2 / p | 4 | Division |

## Fehlerfälle

| Eingabe | Erwartete Ausgabe | Fehlerart |
|----------|-----------------|------------|
| 10 ENTER 0 / p | Division durch 0 | Division durch Null |
| + | – | Stack Underflow |
| d auf leerem Stack | – | Stack Underflow |
| Mehr als 32 Zahlen | – | Stack Overflow |
