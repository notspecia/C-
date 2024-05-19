/*
    Autore:  Nome Cognome
    Data: gg/mm/aaaa

    Titolo: Testo esercizio

*/
#include "TaxesRules.h"

int main() {
  // Ottieni il reddito;
  double reddito;
  double tasse;

  reddito = getIncome("Inserisci il reddito dei dipendenti: ");

  // Calcola le tasse
  tasse = computeTaxes(reddito);

  // Stampa le tasse dei dipendenti
  printTaxes(tasse);

  return 0;
}
