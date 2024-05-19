/* Leggi una stringa e determina quante vocali contiene. */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // inserimento variabili
    string parola;  // parola da inserire
    string vocali;  // le vocali
    int cont;       // tiene il conteggio delle vocali
    int i;          // iteratore x la parola
    int j;          // iteratore per le vocali

    // inizializzazione variabili
    cont = 0;
    vocali = "aeiouAEIOU";

    // input utente
    cout << "inserisci una stringa: ";
    getline(cin, parola);

    // 2 cicli per effettuare controllo su ogni lettera della parola se ce una vocale, se c'è una vocale il cont aumenta
    for (i = 0; i < parola.length(); i++) {
        for (j = 0; j < vocali.length(); j++) {
            if (vocali[j] == parola[i]) {
                cont++;
            }
        }
    }

    cout << "la parola contiene in totale: " << cont << " vocali" << endl;

    return 0;
}