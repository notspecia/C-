/*Leggere un array di interi di N posizioni, N dato in input. Dire se i valori memorizzati
nell’array sono in ordine crescente oppure no.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void ordineCrescente(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX]; // dimensione temporanea array
    int N;           // quantità di numeri nell'array

    // funzione per inserimento di N
    leggiN(N, MAX);

    // funzione inserimento dei numeri nell'array
    leggiNumeri(numeri, N);

    // funziona che controlla se sono in ordine crescente
    ordineCrescente(numeri, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge il numero N (1-100) inserito dall'user

parametri formali:
int &N, cons int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX)
{
    do
    {
        cout << "\ninserisci quanti numeri vuoi registrare (2-100): ";
        cin >> N;
    } while (N < 2 || N > MAX);
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



/*funzione che controlla se i numeri sono crescenti o no

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void ordineCrescente(int numeri[], int N)
{
    // dichiarazione variabili
    int i;     // iteratore
    bool flag; // controllo se sono crescenti o no

    // inizializzazione
    flag = false;

    // ciclo che controlla se gli array sono in ordine crescente
    for (i = 1; i < N && flag != true; i++)
    {
        if (numeri[i] < numeri[i - 1])
        {
            cout << "\nNON SONO crescenti.";
            flag = true;
        }
    }

    // se i numeri sono crescenti
    if (flag == false)
    {
        cout << "\nSONO crescenti.";
    }
}