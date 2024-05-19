/* Leggi una frase e stampala in ordine inverso.

Esempio:
input: CIAO COME STAI? output: ?IAST EMOC OAIC */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // inserimento variabili
    string frase;  // frase da inserire

    // input utente
    cout << "inserisci una frase: ";
    getline(cin, frase);

    // funzione per invertire la parola
    reverse(frase.begin(), frase.end());

    cout << "la frase finale invertita e: " << frase;
    return 0;
}