/*Memorizzare in un array di 100 posti i primi cento numeri naturali in ordine inverso.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void numeriInversi(int numeri[], int num);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];  // dimensione array
    int num;          // numero di partenza

    // inizializzazione variabili
    num = 99;

    // funzione che memorizza in ordine inverso i primi 100 numeri, e succesivamente li stampa
    numeriInversi(numeri, num);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che memorizza e poi stampa i primi 100 numeri naturali inversi

parametri formali:
int numeri[], int num

valore restituito:
null
*/
void numeriInversi(int numeri[], int num) {
    // dichiarazione variabili
    int i;  // iteratore

    // ciclo che stampa i 100 numeri naturali in ordine inverso
    for (i = 0; i < 99; i++) {
        numeri[i] = num--;
    }

    // ciclo che stampa
    for (i = 0; i < MAX; i++) {
        cout << numeri[i] << endl;
    }
}
