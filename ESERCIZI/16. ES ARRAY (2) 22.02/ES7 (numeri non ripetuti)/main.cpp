/*Leggere un array di N interi, N dato in input. Stampare solo i numeri che appaiono nell’array
una volta soltanto.
Esempio: se l’array contiene 1, 2, 3, 1, 2, 4 il programma stamperà 3, 4 .*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX); 
void leggiNumeri(int numeri[], int N);
void numeriSingoli(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];  // dimensione dell'array
    int N;            // quantità di numeri nell'array

    // funzione per inserimento di N
    leggiN(N, MAX);

    // funzione inserimento dei numeri nell'array
    leggiNumeri(numeri, N);

    // funzione che verifica quale numero è ripetuto + volte nell'array
    numeriSingoli(numeri, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge il numero N (1-100) inserito dall'user

parametri formali:
int &N, const int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX) {
    do {
        cout << "\ninserisci quanti numeri vuoi registrare (1-100): ";
        cin >> N;
    } while (N < 1 || N > MAX);
}



/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[], int N

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



/*funzione che stampa i numeri che non sono ripetuti nell'array
parametri formali:
int numeri[], int N

valore restituito:
null
*/
void numeriSingoli(int numeri[], int N) {
    // dichiarazione variabili
    int i;
    int j;
    int count;  // conteggio di quante volte viene ripetuto un numero

    cout << "\n\necco la lista dei numeri che non sono ripetuti:" << endl;

    // cicli per verificare quali sono i numeri non ripetuti (controllo su ogni numero)
    for (i = 0; i < N; i++) {
        count = 0;  // reset del count

        for (j = 0; j < N; j++) {
            if (numeri[i] == numeri[j]) {
                count++;
            }
        }
        if (count < 2) {
            cout << numeri[i] << endl;
        }
    }
}