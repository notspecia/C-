#include <iostream>
#include <string>
#include "libri.h"
using namespace std;


/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che chiede di inserire la quantità dei libri presenti nell'archivio

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "\ninserisci il numero di libri in archivio: ";
        cin >> N;
    } while (N <= 0 || N > LIBRI_MAX);
}

/*funzione che memorizza informazioni di ogni libro nella tabella libri

parametri formali:
libri tabella[LIBRI_MAX], int N

valore restituito:
null
*/
void caricaTabella(libri tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che fa inserire informazioni di ogni libro
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI " << i + 1 << " LIBRO ***\n";

        // codice del libro
        cout << "inserisci il codice del libro: ";
        cin >> tabella[i].codice;

        // da quante pagine è composto il libro
        do
        {
            cout << "N di pagine del libro: ";
            cin >> tabella[i].numeroPagine;
        } while (tabella[i].numeroPagine <= 0);

        // costo del libro
        do
        {
            cout << "prezzo del libro: ";
            cin >> tabella[i].costo;
        } while (tabella[i].costo <= 0);
    }
}

/*funzione che calcola il costo x pagina di ogni libro

parametri formali:
libri tabella[LIBRI_MAX], int N

valore restituito:
null
*/
void prezzoPagina(libri tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che calcola il prezzo per pagina di ogni libro
    for (i = 0; i < N; i++)
    {
        tabella[i].costoXpagina = tabella[i].costo / tabella[i].numeroPagine;
    }
}

/*funzione che stampa in ordine crescente il costo x pagina di ogni libro

parametri formali:
libri tabella[LIBRI_MAX], int N

valore restituito:
null
*/
void stampaPagina(libri tabella[], int N)
{
    // dichiarazione variabili
    int i;
    int j;

    // ciclo per mettere in ordine crescente il costo x pagina per ogni libro
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (tabella[i].costoXpagina > tabella[j].costoXpagina)
            {
                swap(tabella[i], tabella[j]);
            }
        }
    }

    // ciclo stampa costo x pagina di ogni libro
    cout << "\n\n\n*** LISTA ORDINE CRESCENTE PREZZO X PAGINA DEI LIBRI***";
    for (i = 0; i < N; i++)
    {
        cout << "\nLIBRO con codice " << tabella[i].codice << ", prezzo per pagina --> " << tabella[i].costoXpagina << endl;
    }
}
