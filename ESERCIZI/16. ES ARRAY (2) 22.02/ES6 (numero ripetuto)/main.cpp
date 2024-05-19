/*Leggere un array di numeri reali di N posizioni, N dato in input. Stampare il numero che
compare più volte all’interno dell’array, qualora ci siano più numeri che compaiono lo
stesso numero di volte stampare quello che compare per primo.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void ripetizioni(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX]; // dimensione dell'array
    int N;           // quantità di numeri nell'array

    // funzione per inserimento di N
    leggiN(N, MAX);

    // funzione inserimento dei numeri nell'array
    leggiNumeri(numeri, N);

    // funzione che verifica quale numero è ripetuto + volte nell'array
    ripetizioni(numeri, N);

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

/*funzione che stampa il numero che è ripetuto + volte nell'array
parametri formali:
int numeri[], int N

valore restituito:
null
*/
void ripetizioni(int numeri[], int N)
{
    // dichiarazione variabili
    int i;
    int j;
    int count;    // conteggio di quante volte viene ripetuto un numero
    int countmax; // conteggio massimo visto fino a quel momento
    int max;      // numero che viene ripetuto + volte nell'array

    countmax = 0;

    // cicli per verificare qual'è il numero ripetuto più volte nell'array (controllo su ogni numero)
    for (i = 0; i < N; i++)
    {
        count = 0; // reset del count

        for (j = 0; j < N; j++)
        {
            if (numeri[i] == numeri[j])
            {
                count++;
            }
        }
        if (count > countmax)
        {
            countmax = count;
            max = numeri[i];
        }
    }

    // stampa del numero ripetuto + volte
    cout << "\n\nil numero ripetuto + volte nell'array e: " << max << endl;
}