#ifndef _TAXES_RULES_
#define _TAXES_RULES_

#include <iostream>
#include <string>
using namespace std;

/* scopo -- ottenere il reddito dei dipendenti
  input -- un prompt di stringa da mostrare all'utente
 output -- un valore double che rappresenta il reddito
*/
double getIncome(string);

/* scopo -- calcolare le tasse per un dato reddito
   input -- un valore double che rappresenta il reddito
 output -- un valore double che rappresenta le tasse
*/
double computeTaxes(double);

/* scopo -- mostrare le tasse all'utente
   input -- un valore double che rappresenta le tasse
   output -- Nessuno
*/
void printTaxes(double);

#endif
