#include "TaxesRules.h"
#include <iostream>

double computeTaxes(double reddito) {
  if (reddito < 5000)
    return 0.0;
  return 0.07 * (reddito - 5000.0);
}

double getIncome(string prompt) {
  double reddito;
  cout << prompt;
  cin >> reddito;
  return reddito;
}

void printTaxes(double tasse) { cout << "Le tasse sono $" << tasse << endl; }
