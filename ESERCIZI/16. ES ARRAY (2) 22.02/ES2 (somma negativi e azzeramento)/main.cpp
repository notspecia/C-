/*Dopo aver letto e memorizzato N numeri reali in un array , N dato in input, calcolare la
somma di quelli negativi e, successivamente, sovrascrivere il loro valore con zero.
Stampare la somma calcolata e l’array modificato.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
int calcoloNegativi(int numeri[], int N);
void nuovoArraySomma(int numeri[], int N, int somma);


/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX]; // dimensione temporanea array
    int N;           // quantità di numeri nell'array
    int somma;       // somma dei numeri negativi

    // funzione per inserimento di N
    leggiN(N, MAX);

    // funzione inserimento dei numeri nell'array
    leggiNumeri(numeri, N);

    // funzione che somma i numeri negativi e li trasforma in 0
    somma = calcoloNegativi(numeri, N);

    // funzione che stampa la somma e il nuovo array
    nuovoArraySomma(numeri, N, somma);

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
void leggiN(int &N, const int MAX)
{
    do
    {
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
void leggiNumeri(int numeri[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo per memorizzare i numeri inseriti dall'user
    for (i = 0; i < N; i++)
    {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}



/*funzione che somma i numeri negativi e li trasforma in 0

parametri formali:
int numeri[], int N

valore restituito:
int somma
*/
int calcoloNegativi(int numeri[], int N)
{

    // dichiarazione variabili
    int i;
    int somma;

    // inizializzazione variabili
    somma = 0;

    for (i = 0; i < N; i++)
    {
        if (numeri[i] < 0)
        {
            somma += numeri[i];
            numeri[i] = 0;
        }
    }
    return somma;
}



/*funzione che stampa il nuovo array modificato, e la somma dei negativi

parametri formali:
int numeri[], int N

valore restituito:
int somma
*/
void nuovoArraySomma(int numeri[], int N, int somma)
{
    // dichiarazione variabili
    int i;

    cout << "\n\nla somma dei negativi e: " << somma;

    // ciclo che stampa il nuovo array
    cout << "\n\nnuovo array: \n";
    for (i = 0; i < N; i++)
    {
        cout << numeri[i] << endl;
    }
}