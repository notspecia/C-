/*Creare una funzione che ricevuti due interi che rappresentano numeratore e denominatore
di una frazione, riduca la frazione ai minimi termini.
Creare poi un programma che legga due frazioni le riduca ai minimi termini e verifichi se
abbiano lo stesso denominatore.
Suggerimento: cercare sul web l’algoritmo che semplifichi una frazione ai minimi termini
oppure l’algoritmo per calcolare l’M.C.D. tra due numeri.*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;





/*funzione che legge il numeratore e il denominatore delle frazioni

parametri formali:
string text

valore restituito:
int numero
*/
int leggiNumero(string text)
{
    // dichiarazione variabili
    int numero;

    // input utente controllo numeratore > 0
    cout << "\ninserisci il " << text << " frazione: ";
    cin >> numero;
    while (numero < 0)
    {
        cout << "re-inserisci il " << text << " frazione (>0!): ";
        cin >> numero;
    }

    return numero;
}






/*funzione che effettua la riduzione del numeratore e denominatore (tramite &)

parametri formali:
int &numeratore, int &denominatore

valore restituito:
null
*/
void riduciFrazione(int &numeratore, int &denominatore)
{
    // dichiarazione delle variabili
    int i;   // il numero che divide il num e il denominatore
    int min; // il più basso fra numeratore e denominatore

    // inizializzazione delle variabili
    i = 2;  //partiamo da 2 perchè tutti i numeri sono divisibili per 1

    // ciclo che permette di ridurre la frazione ai minimi termini
    do
    {
        if (numeratore > denominatore)
        {
            min = denominatore;
        }
        else
        {
            min = numeratore;
        }
        if ((numeratore % i == 0) && (denominatore % i == 0))
        {
            numeratore = numeratore / i;
            denominatore = denominatore / i;
        }
        else
            i++;
    } while (i <= min);
}




int main()
{
    // dichiarazione variabili
    int numeratore1;
    int numeratore2;
    int denominatore1;
    int denominatore2;

    // lettura della prima frazione e stampa della prima frazione
    numeratore1 = leggiNumero("numeratore della prima");
    denominatore1 = leggiNumero("denominatore della prima");
    cout << "prima frazione: " << numeratore1 << "/" << denominatore1 << endl;

    // lettura della seconda frazione
    numeratore2 = leggiNumero("numeratore della seconda");
    denominatore2 = leggiNumero("denominatore della seconda");
    cout << "seconda frazione: " << numeratore2 << "/" << denominatore2 << endl;

    // riduzione frazioni ai minimi termini
    riduciFrazione(numeratore1, denominatore1);
    cout << "\n\nora la nuova prima frazione e: " << numeratore1 << "/" << denominatore1 << endl;
    riduciFrazione(numeratore2, denominatore2);
    cout << "\nora la nuova seconda frazione e: " << numeratore2 << "/" << denominatore2 << endl;

    // stampa e controllo se le 2 frazioni hanno lo stesso denominatore
    if (denominatore1 == denominatore2)
    {
        cout << "\nLe frazioni hanno lo stesso denominatore." << endl;
    }
    else
    {
        cout << "\nLe frazioni non hanno lo stesso denominatore." << endl;
    }
    return 0;
}