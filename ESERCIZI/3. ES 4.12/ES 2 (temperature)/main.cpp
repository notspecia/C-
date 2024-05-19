/*Si abbia in input un numero N di misure di temperatura, in output si vuole la media
aritmetica di tali temperature.*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // inserimento variabili
    int N;        // Q. di temperature
    float temp;   // temperatura
    float somma;  // somma delle temperature
    float media;  // media delle temperature
    int i;        // iteratore

    // inizializzazione variabili
    somma = 0;
    media = 0;

    // input utente
    cout << "inserisci la quantita di temperature: ";
    cin >> N;

    // controllo Q inserita
    while (N <= 0) {
        cout << "inserisci la quantita di temperature (>0!): ";
        cin >> N;
    }
	cout<<endl;
	
    // richiesta di inserire N temperature per poi sommarle
    for (i = 0; i < N; i++) {
        cout << "inserisci la " << i + 1 << " temperatura: ";
        cin >> temp;
        somma += temp;
    }

    // calcolo e stampa della media
    media = somma / N;

    cout << "\nla media delle temperature che hai inserito e di: " << media;

    return 0;
}