/*Dopo aver caricato in memoria un array di numeri interi con 10 componenti,
calcolare il prodotto delle componenti.*/

#include <iostream>
using namespace std;

int const MAX = 10;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiNumeri(int numeri[]);
int prodottoNumeri(int numeri[]);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX]; // EX:= {1,2,3,4,5,6,7,8,9,10}; array dei numeri interi
    int prodotto;   // prodotto dei numeri interi

    // funzione che memorizza i numeri nell'array
    leggiNumeri(numeri);

    // funzione che fa il prodotto dei numeri memorizzati
    prodotto = prodottoNumeri(numeri);

    // stampa del prodotto
    cout << "\nIl prodotto e: " << prodotto << endl;

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[]

valore restituito:
null
*/
void leggiNumeri(int numeri[])
{

    // dichiarazione variabili
    int i;

    // ciclo che memorizza 10 numeri
    for (i = 0; i < 10; i++)
    {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}



/*funzione che fa il prodotto dei numeri memorizzati nell'array

parametri formali:
int numeri[]

valore restituito:
int prodotto
*/
int prodottoNumeri(int numeri[])
{

    // dichiarazione variabili
    int prodotto = 1;
    int i;

    // ciclo che fa il prodotto
    for (i = 0; i < 10; i++)
    {
        prodotto *= numeri[i];
    }

    return prodotto;
}