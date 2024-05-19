/*Leggere un array di N numeri reali, N dato in input. Dire se ogni valore presente nell’array è
minore della somma dei numeri presenti nelle celle che lo precedono.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void sommaPrecedenti(int numeri[], int N);

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

    // funzione che verifica se il numero è < alla somma dei numeri precedenti
    sommaPrecedenti(numeri, N);

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

/*funzione che verifica se ogni numero dell'array, è inferiore alla somma dei precdenti numeri

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void sommaPrecedenti(int numeri[], int N)
{
    // dichiarazione variabili
    int i;
    int j;
    int somma; // somma dei numeri precedenti di numeri[i]

    cout << endl;

    // cicli per verificare se il numero è < della somma dei numeri precdenti
    for (i = 0; i < N; i++)
    {
        somma = 0; // reset della somma

        for (j = 0; j < i; j++)
        {
            somma += numeri[j];
        }

        // stampa se il numero è inferiore alla somma dei numeri precedenti
        if (numeri[i] < somma)
        {
            cout << "\nil numero in posizione " << i + 1 << " (" << numeri[i] << "), e inferiore alla somma dei numeri precedenti = " << somma << endl;
        }
    }
}