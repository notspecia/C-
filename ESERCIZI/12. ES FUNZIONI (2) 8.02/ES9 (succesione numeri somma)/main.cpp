/*Creare una funzione che legga una successione di numeri reali positivi che termini al
primo numero che rende la successione non crescente. Tale funzione deve restituire la
somma di tutti i numeri inseriti. Creare il programma principale che richiama due volte la
funzione e stampa la somma più alta.
Esempio:
input: 2 5 28 10 output funzione: 35 (2 + 5 + 28 = 35)
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;





/*funzione che somma i numeri reali in ordine crescente

parametri formali:
null

valore restituito:
int somma
*/
int successioni()
{
    // dichiarazione variabili
    int num;   // numero da inserire
    int numax; // il numero inserito se è piu alto di quello precedente, assume il valore di num max
    bool flag; // fino a quando si inseriscono numeri piu grandi è sempre falso
    int somma; // somma dei numeri inseriti
    int i;     // conteggio dei numeri

    // inizializzazione variabili
    somma = 0;
    numax = -1;
    i = 0;
    flag = false;

    // ciclo che somma i numeri reali in ordine crescente
    do
    {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> num;
        while (num < 0)
        {
            cout << "reinserisci il " << i + 1 << " numero: ";
            cin >> num;
        }
        if (num > numax)
        {
            somma += num;
            numax = num;
            i++;
        }
        else
        {
            flag = true;
        }

    } while (flag != true);

    return somma;
}





/*funzione che stampa la somma

parametri formali:
int somma

valore restituito:
null
*/
void stampaSomma(int somma1, int somma2)
{

    // stampa di qual'è la somma più alta tra le 2
    if (somma1 > somma2)
    {
        cout << "\nsomma1 (" << somma1 << ")  maggiore di somma2 (" << somma2 << ")";
    }
    else if (somma1 = somma2)
    {
        cout << "\nsomma1 (" << somma1 << ") e uguale alla somma2 (" << somma2 << ")";
    }
    else
    {
        cout << "\nsomma2 (" << somma2 << ") e maggiore alla somma1 (" << somma1 << ")";
    }
}




int main()
{
    // dichiarazione variabili
    int somma1; // somma dei numeri reali crescenti
    int somma2; // somma dei numeri reali crescenti
    // somma dei numeri reali in ordine crescente
    somma1 = successioni();
    somma2 = successioni();

    // stampa della somma
    stampaSomma(somma1, somma2);

    return 0;
}