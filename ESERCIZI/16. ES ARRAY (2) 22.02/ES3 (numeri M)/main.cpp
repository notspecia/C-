/*Leggere un array di interi di N posizioni, N dato in input. Leggere un ulteriore numero intero
M e dire quanti numeri memorizzati nell’array sono inferiori e quanti superiori di M.*/

#include <iostream>
using namespace std;
const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiNM(int &N, string , const int MAX);
void leggiNumeri(int numeri[], int N);
void arrayM(int numeri[], int N, int M, int &count1, int &count2);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX];
    int N;      // quantità di numeri nell'array
    int M;      // numero da superare
    int count1; // contatore dei numeri > M
    int count2; // contatore dei numeri < M

    // funzione che legge N (la quantità dell'array)
    leggiNM(N, "inserisci quanti numeri vuoi registrare (1-100): ", MAX);

    // funzione che memorizza i numeri nell'array
    leggiNumeri(numeri, N);

    // funzione che legge M e dice quanti numeri dell'array sono < M e quanti > M
    leggiNM(M, "\n\n\ninserisci il numero M di controllo (1-100): ", MAX);
    arrayM(numeri, N, M, count1, count2);

    // stampa dei contatori
    cout << "\ntra i numeri che hai inserito:\n"
         << count1 << " numeri sono > M\n"
         << count2 << " numeri sono < M\n"
         << endl;

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
void leggiNM(int &N, string text, const int MAX)
{
    do
    {
        cout << text;
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

/*funzione che controlla quanti numeri degli array sono > M oppure < M

parametri formali:
int numeri[], int N, int M, &count1, &count2

valore restituito:
null
*/
void arrayM(int numeri[], int N, int M, int &count1, int &count2)
{
    // dichiarazione variabili
    int i; // iteratore

    // inizializzazione variabili
    count1 = 0; // count dei numeri > M
    count2 = 0; // count dei numeri < M

    for (i = 0; i < N; i++)
    {
        if (numeri[i] > M)
        {
            count1++;
        }
        else if (numeri[i] < M)
        {
            count2++;
        }
    }
}
