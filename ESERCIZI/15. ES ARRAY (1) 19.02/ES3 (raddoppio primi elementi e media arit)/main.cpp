/* Dopo aver caricato in memoria un array di numeri reali con N componenti, N inserito in input,
raddoppiare il valore delle prime tre componenti e stampare la media aritmetica di tutte le componenti.*/

#include <iostream>
using namespace std;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiMax(int &N);
void leggiNumeri(int numeri[], int N);
int calcoloMedia(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {

    // dichiarazione variabili
    int numeri[100];  // massima capienza dell'array, non è per forza 100!
    int N;            // decisione utente quanti numeri registrare nella memoria
    float media;      // media aritmetica

    // funzione che legge numero N
    leggiMax(N);

    // funzione per memorizzare i numeri nell'array
    leggiNumeri(numeri, N);

    // funzione che calcola la media
    media = calcoloMedia(numeri, N);

    // calcolo e stampa della media artitmetica
    media /= N;
    cout << "\n\nmedia aritmetica dei numeri che hai inserito: " << media;

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge il numero N (1-100) inserito dall'user

parametri formali:
int &N

valore restituito:
null
*/
void leggiMax(int &N) {
    do {
        cout << "\ninserisci quanti numeri vuoi registrare (1-100): ";
        cin >> N;
    } while (N < 1 || N > 100);
}



/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[]

valore restituito:
null
*/
void leggiNumeri(int numeri[], int N) {

    // dichiarazione variabili
    int i;

    // ciclo per memorizzare i numeri inseriti dall'user
    for (i = 0; i < N; i++) {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}



/*funzione che moltiplica * 2 i primi 3 contenuti e inizio calcolo della media

parametri formali:
int numeri[], int M

valore restituito:
int count
*/
int calcoloMedia(int numeri[], int N) {

    // dichiarazione variabili
    int i;
    int media;

    // inizializzazione variabili
    media = 0;

    // ciclo che moltiplica * 2 i primi 3 contenuti dell'array
    for (i = 0; i < N; i++) {
        if (i >= 0 && i < 3) {
            media += numeri[i] * 2;
        } else {
            media += numeri[i];
        }
    }
    return media;
}