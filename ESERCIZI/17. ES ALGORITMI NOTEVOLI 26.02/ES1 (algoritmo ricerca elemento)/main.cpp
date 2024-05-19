/*PRIMO ALGORITMO ricerca elemento*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
const int MAX = 15;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/
void generazioneK(int &K);
void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void trovaChiave(int numeri[], int N, int K);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];
    int K;
    int N;

    // inizializzazione del seme
    srand(time(NULL));

    // funzione che genera la chiave (K) casualmente
    generazioneK(K);

    // funzione che legge la dimensione dell'array
    leggiN(N, MAX);

    // funzione che legge i numeri dell'array
    leggiNumeri(numeri, N);

    // funzione che cicla ogni elemento e contolla se = K
    trovaChiave(numeri, N, K);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che genera la chiave K causalmente

parametri formali:
null


valore restituito:
int &K
*/
void generazioneK(int &K) {
    // generazione di un numero tra 1 e 10
    K = rand() % 10 + 1;
    cout << "la chiave K e: " << K << endl;
}

/*funzione che legge il numero N (1-15) inserito dall'user

parametri formali:
int &N, const int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX) {
    do {
        cout << "\ninserisci quanti numeri vuoi registrare nell'array (1-15): ";
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

/*funzione che cicla elementi dell'array fino a quando != K

parametri formali:
int numeri[], int N, int K

valore restituito:
null
*/
void trovaChiave(int numeri[], int N, int K) {
    // dichiarazione variabili
    int i;

    // ciclo che controlla elementi se sono = K, esce dal ciclo quando viene trovato
    for (i = 0; i <= N && K != numeri[i]; i++) {
    }

    // stampa in base alla flag se è vera(K trovato) oppure se è falsa(K non trovato)
    if (i <= N) {
        cout << "\n\nla chiave K (" << K << ") e stata trovata tra gli elementi dell'array" << endl;

    } else {
        cout << "\n\nla chiave K (" << K << ") NON e stata trovata tra gli elementi dell'array" << endl;
    }
}