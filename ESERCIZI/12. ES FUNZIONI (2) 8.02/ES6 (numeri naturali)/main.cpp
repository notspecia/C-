/*Creare una funzione che restituisca se un numero intero è naturale o no.
Creare poi un programma che riceva un numero n (passato dall’utente). Nel caso questo
sia naturale, richieda all’utente di inserire altri n numeri e alla fine stampi quanti di questi
sono naturali.
Ricorda i numeri naturali sono numeri interi N >= 0
Es: 4 è un numero naturale, -5 non è un numero naturale.*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



/*funzione controllo del primo numero

parametri formali:
null

valore restituito:
int numero naturale 1
*/
int Qnumeri()
{
    // dichiarazione variabili
    int numero1; // primo numero da inserire

    // input utente
    cout << "inserisci un numero naturale: ";
    cin >> numero1;
    while (numero1 < 0)
    {
        cout << "reinserisci un numero naturale (>=0!): ";
        cin >> numero1;
    }

    // N numeri da inserire dati dal primo numero naturale
    cout << "ora inseriscimi " << numero1 << " numeri: ";
    cout << endl;

    return numero1;
}





/*funzione stampa e controllo dei numeri naturali e non, + conteggio dei numeri naturali

parametri formali:
int numero naturale 1

valore restituito:
int count
*/
int letturaNumeri(int N)
{

    // dichiarazione variabili
    int i;         // iteratore
    int numero;    // numero da inserire
    int conteggio; // conteggio di quanti numeri naturali ci sono

    // inizializzazione variabili
    i = 0;
    conteggio = 0;

    // ciclo che chiede i numeri
    while (i < N)
    {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numero;

        if (numero < 0)
        {
            cout << numero << " non e naturale!\n";
        }
        else
        {
            cout << numero << " e naturale!\n";
            conteggio++;
        }
        i++;
    }
    return conteggio;
}






/*funzione stampa del conteggio dei numeri naturali
parametri formali:
int count

valore restituito:
null
*/
void stampaCount(int count)
{
    cout << "\nil numero totale di numeri naturali, e di: " << count;
}





int main()
{
    // dichiarazione variabili
    int N;     // Q. numeri da inserire
    int count; // conteggio di quanti sono i numeri naturali

    // inizializzazione variabili
    N = 0;
    count = 0;

    // leggi primo numero e inizializza quanti numeri dovrai inserire
    N = Qnumeri();

    // lettura e stampa dei numeri naturali
    count = letturaNumeri(N);

    // stampa di quanti numeri naturali ci sono
    stampaCount(count);

    return 0;
}