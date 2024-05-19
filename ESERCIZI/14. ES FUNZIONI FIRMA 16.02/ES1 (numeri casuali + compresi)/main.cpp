/*Scrivere una funzione che dati due numeri interi x e y, calcoli la somma di tutti i numeri
dispari compresi tra x e y. Costruire un programma che richiami n volte la funzione su n
differenti intervalli (n dato in input).
Suggerimento: utilizzare la funzione di generazione di numeri pseudocausali.*/

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiNumero();
void generazione(int &, int &);
void numeriDispari(int &, int &);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{

    // inserimento variabili
    int n;     // quantità degli intervalli
    int x;     // primo numero
    int y;     // secondo numero
    int num;   // numeri compresi tra x ed y
    int somma; // somma dei numeri compresi
    int i;     // iteratore

    // inizializzazione seme per tempo casuale
    srand(time(NULL));

    // leggi quantità intervalli
    n = leggiNumero();
    cout << endl;

    // ciclo che va in base alla Q + leggi numeri (x,y) fino a quando non supera y.
    for (i = 0; i < n; i++)
    {

        // generazione dei numeri casuali
        generazione(x, y);

        // inizializzazione e reset della x e della somma
        num = x;
        somma = 0;
        cout << endl;

        do
        {
            numeriDispari(num, somma);

        } while (num < y);

        // stampa della somma dell'intervallo
        cout << "\nla somma del " << i + 1 << " intervallo e: " << somma << endl;
        cout << "--------------------------------------------------------------\n\n";
    }
    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge la quantità di intervalli

parametri formali:
null

valore restituito:
int numero
*/
int leggiNumero()
{
    // dichiarazione delle variabili
    int Q; // quantità

    // input N intervalli e controllo > 0
    cout << "\ninserisci la quantita di intervalli che vuoi verificare: ";
    cin >> Q;
    while (Q <= 0)
    {
        cout << "reinserisci la quantita di intervalli che vuoi verificare (>0!): ";
        cin >> Q;
    }
    return Q;
}

/*funzione che genera e stampa 2 numeri casuali(x, y)

parametri formali:
int &x, int &y

valore restituito:
null
*/
void generazione(int &x, int &y)
{

    // generazione numeri casuali (x,y)
    x = rand() % 30 + 1;
    y = x + (rand() % (30 - x));
    cout << "generazione x: " << x << endl;
    cout << "generazione y: " << y << endl;
}


/*funzione che stampa e somma i numeri dispari

parametri formali:
int &num, int &somma

valore restituito:
null
*/
void numeriDispari(int &num, int &somma)
{
    // controllo se il numero è dispari
    if (num % 2 != 0)
    {
        somma += num;
        cout << num << endl;
    }
    num++;
}

