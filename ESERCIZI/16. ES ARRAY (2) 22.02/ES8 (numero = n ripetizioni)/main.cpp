/*Leggere un array di N interi, N dato in input. Verificare se c’è almeno un valore presente un
numero di volte identico al suo valore.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void verificaValore(int numeri[], int N);

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

    // funzione che verifica se il valore è = al numero di volte che è ripetuto
    verificaValore(numeri, N);

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



/*funzione che verifica se il valore = a quante volte è ripetuto nell'array

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void verificaValore(int numeri[], int N)
{
    // dichiarazione variabili
    int i;
    int j;
    bool flag; // cambia se il valore = al numero di ripetizioni
    int count; // conteggio di quante volte viene ripetuto un numero

    // inizializzazione variabili
    flag = false;

    // cicli per verificare se il valore = al numero di volte che viene ripetuto
    for (i = 0; i < N && flag != true; i++)
    {
        count = 0; // reset del count

        for (j = 0; j < N; j++)
        {
            if (numeri[i] == numeri[j])
            {
                count++;
            }
        }

        if (count == numeri[i])
        {
            cout << "\n\nin posizione " << i + 1 << " il numero " << numeri[i] << ", e = al numero di ripetizioni (" << count << ")";
            flag = true;
        }
    }
}