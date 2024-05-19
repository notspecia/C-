/*Leggere un array di N interi, N dato in input. Verificare se contiene tutti valori diversi.*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void controlloDiversi(int numeri[], int N);

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
    controlloDiversi(numeri, N);

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

/*funzione che stampa i numeri che non sono ripetuti nell'array
parametri formali:
int numeri[], int N

valore restituito:
null
*/
void controlloDiversi(int numeri[], int N)
{
    // dichiarazione variabili
    int i;
    int j;
    int count; // conteggio se il numero è ripetuto + di 2 volte
    bool flag; // cambia se ci sono 2 o + ripetizioni

    // inizializzazione variabili
    flag = false;

    // cicli per verificare quali sono i numeri non ripetuti (controllo su ogni numero)
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
        if (count >= 2)
        {
            flag = true;
        }
    }

    // stampa in base alla flag se è vera(ci sono ripetizioni) oppure se è falsa(non ci sono ripetizioni)
    if (flag == false)
    {
        cout << "\n\ni numeri che hai inserito SONO tutti diversi!" << endl;
    }
    else
    {
        cout << "\n\ni numeri che hai inserito NON SONO tutti diversi!" << endl;
    }
}