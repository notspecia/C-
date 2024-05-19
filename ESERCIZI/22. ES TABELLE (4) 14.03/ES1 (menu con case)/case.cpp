#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "case.h"
using namespace std;

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che apre il menu di scelta all'utente

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu()
{

    // dichiarazione variabile
    int scelta;

    // schermata menu
    cout << "\n\n\n----------------------------------------------------------------------------------------" << endl;
    cout << "1. Inserimento di una casa" << endl;
    cout << "2. Stampa di tutte le case" << endl;
    cout << "3. Stampa delle case in AFFITTO ordinate per classe energetica (crescente)" << endl;
    cout << "4. Stampa delle case comprese tra due prezzi dati in input" << endl;
    cout << "5. Esci\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette inserimento informazioni di una casa

parametri formali:
casa tabella[], int &N, char classeEnergetiche[]

valore restituito:
null
*/
void inserimentoCasa(casa tabella[], int &N, char classeEnergetiche[])
{

    // dichiarazione variabili
    int i;
    bool flag;

    // inizializzazione variabili
    flag = false;

    // controllo che non si superi il limite massimo di case (10)
    if (N < N_MAX_CASE)
    {
        cout << "\n\n*** INSERIMENTO DATI " << N + 1 << " CASA ***\n";

        // inserimento RANDOMICO nella tabella superficie in mq della casa (28 - 100)
        tabella[N].superficie = 28 + (rand() % (100 - 28));
        cout << "\ninserisci la superficie della casa (mq): " << tabella[N].superficie;

        // inserimento nella tabella della classe energetica della casa
        do
        {
            cout << "\n\ninserisci la classe energetica della casa (A-F): ";
            cin >> tabella[N].classeEnergia;

            for (i = 0; i < energetica && flag != true; i++)
            {

                if (tabella[N].classeEnergia == classeEnergetiche[i])
                {
                    flag = true;
                }
            }
        } while (!flag);

        // inserimento RANDOMICO nella tabella il costo della casa
        tabella[N].costo = prezzoMIN + (rand() % (prezzoMAX - prezzoMIN));
        cout << "\ninserisci il prezzo della casa: " << tabella[N].costo;

        // inserimento RANDOMICO nella tabella del tipo di contratto della casa
        tabella[N].contratto = rand() % 2 + 0;
        cout << "\n\ninserisci il tipo di contratto (0 VENDITA  1 AFFITTO): " << tabella[N].contratto;

        // incremento delle case totali registrate
        N++;
    }
    else
    {
        cout << "\nnumero CASE max superato!";
    }
}

/*funzione che stampa le case e le sue informazioni

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void stampaCase(casa tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo di stampa delle case
    cout << "\n\n***STAMPA DI TUTTE LE* CASE***\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " CASA -->  superficie (mq): " << tabella[i].superficie;
        cout << "  classe energetica: " << tabella[i].classeEnergia;
        cout << "  costo: " << tabella[i].costo;
        cout << "  tipo di contratto: ";
        if (tabella[i].contratto == 0)
        {
            cout << "vendita\n\n";
        }
        else
        {
            cout << "affitto\n\n";
        }
    }
}

/*funzione che stampa delle case in affitto in ordine di classe energetica

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void stampaCaseAffitto(casa tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;
    int count;                // conteggio delle case in affitto
    casa affitto[N_MAX_CASE]; // tabella provvisoria utile per lavorare con le case in affitto

    // inizializzazione variabili
    count = 0;

    // ciclo che memorizza le case in affitto nella tabella casa affitto[]
    for (i = 0; i < N; i++)
    {
        if (tabella[i].contratto == 1)
        {
            affitto[count] = tabella[i];
            count++;
        }
    }

    // ciclo che ordina in ordine crescente le case in affitto
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (affitto[i].classeEnergia > affitto[j].classeEnergia)
            {
                swap(affitto[i], affitto[j]);
            }
        }
    }

    // stampa delle case in affitto in ordine crescente
    cout << "\n\n***STAMPA ORDINE CRESCENTE CASE AFFITTO***\n\n";
    for (i = 0; i < count; i++)
    {

        cout << i + 1 << " CASA AFFITTO -->  superficie (mq): " << affitto[i].superficie;
        cout << "  classe energetica: " << affitto[i].classeEnergia;
        cout << "  costo: " << affitto[i].costo;
        cout << "  tipo di contratto: affitto\n\n ";
    }
}

/*funzione che stampa le case comprese tra due prezzi dati in input

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void stampaCasePrezzo(casa tabella[], int N)
{

    // dichiarazione variabili
    float prezzo1;
    float prezzo2;
    int i;

    // inserimento dei prezzi
    do
    {
        cout << "\ninserisci il primo prezzo: ";
        cin >> prezzo1;
    } while (prezzo1 < prezzoMIN);

    do
    {
        cout << "\ninserisci il secondo prezzo: ";
        cin >> prezzo2;
    } while (prezzo2 < prezzoMIN);

    // se il prezzo 2 è minore del primo prezzo1 (cosi riesce a comprendere anche in questo caso i costi)
    if (prezzo2 < prezzo1)
    {
        swap(prezzo2, prezzo1);
    }

    // ciclo di stampa delle case che hanno un prezzo compreso tra i 2 prezzi dati in input
    cout << "\n\n***STAMPA CASE COMPRESE TRA " << prezzo1 << " / " << prezzo2 << "euro***\n\n";
    for (i = 0; i < N; i++)
    {
        if (tabella[i].costo >= prezzo1 && tabella[i].costo <= prezzo2)
        {
            cout << i + 1 << " CASA -->  superficie (mq): " << tabella[i].superficie;
            cout << "  classe energetica: " << tabella[i].classeEnergia;
            cout << "  costo: " << tabella[i].costo;
            cout << "  tipo di contratto: ";
            if (tabella[i].contratto == 0)
            {
                cout << "vendita\n\n";
            }
            else
            {
                cout << "affitto\n\n";
            }
        }
    }
}
