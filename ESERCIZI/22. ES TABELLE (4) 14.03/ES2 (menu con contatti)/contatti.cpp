#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "contatti.h"
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

    // dichiarazione variabili
    int scelta;

    // schermata menu
    cout << "\n\n\n--------------------------------------------------------------------------------------------" << endl;
    cout << "1. Inserimento di N contatti" << endl;
    cout << "2. Stampa dei contatti presenti" << endl;
    cout << "3. Eliminazione dei contatti appartenenti a una categoria (data in input)" << endl;
    cout << "4. Stampa ordinata alfabeticamente per cognome dei contatti appartenenti a una categoria (data in input)" << endl;
    cout << "5. Esci\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette inserimento di contatti

parametri formali:
contatti tabella[], int &N, int categorie[]

valore restituito:
null
*/
void inserimentoContatti(contatti tabella[], int &N, int categorie[])
{

    // dichiarazione variabili
    int i;
    bool flag;

    // inizializzazione variabili
    flag = false;

    // controllo che non si superi il limite massimo di contatti (10)
    if (N < CONTATTI_MAX)
    {
        cout << "\n\n*** INSERIMENTO DATI " << N + 1 << " CONTATTO ***\n";

        // inserimento nome del contatto nella tabella
        cout << "\ninserisci il nome del contatto: ";
        cin.ignore();
        getline(cin, tabella[N].nome);

        // inserimento cognome del contatto nella tabella
        cout << "\ninserisci il cognome del contatto: ";
        cin.ignore();
        getline(cin, tabella[N].congome);

        // inserimento RANDOMICO del numero di telefono nella tabella
        tabella[N].telefono = 3000000 + rand() % 1000000;
        cout << "\ninserisci numero di telefono del contatto: " << tabella[N].telefono;

        // inserimento della categoria nella tabella
        do
        {
            cout << "\n\ninserisci la categoria del contatto (1-5): ";
            cin >> tabella[N].categoria;

            for (i = 0; i < CATEGORIE_MAX && flag != true; i++)
            {

                if (tabella[N].categoria == categorie[i])
                {
                    flag = true;
                }
            }
        } while (!flag);

        // incremento dei contatti totali registrati
        N++;
    }
    else
    {
        cout << "\nnumero CONTATTI max superato!";
    }
}

/*funzione che stampa i contatti e le sue informazioni

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void stampaContatti(contatti tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo di stampa delle case
    cout << "\n\n***STAMPA DI TUTTI I CONTATTI***\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " CONTATTO -->  nome: " << tabella[i].nome;
        cout << "   cognome: " << tabella[i].congome;
        cout << "   N di telefono: " << tabella[i].telefono;
        cout << "   categoria: " << tabella[i].categoria << "\n\n";
    }
}

/*funzione che elimina i contatti appartenenti ad una categoria
parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void cancellaContatti(contatti tabella[], int &N, int categorie[])
{

    // dichiarazione variabili
    int i;
    int j;
    int categoriaInput; // input della categoria da cancellare
    bool flag;          // il valore cambia quando viene inserita una categoria valida

    // inizializzazione variabili
    flag = false;

    // input categoria
    do
    {
        cout << "\ninserisci la categoria da ELIMINARE: ";
        cin >> categoriaInput;

        for (i = 0; i < CATEGORIE_MAX && flag != true; i++)
        {

            if (categorie[i] == categoriaInput)
            {
                flag = true;
            }
        }

    } while (!flag);

    // ciclo con algoritmo che cancella dalla tabella i contatti appartenenti ad una categoria
    // re-inizializzazione iteratore
    i = 0;
    while (i < N)
    {
        if (tabella[i].categoria == categoriaInput)
        {
            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }
            N--; // decremento del numero contatti
        }
        else
        {
            i++;
        }
    }
}

/*funzione che ordina e stampa i contatti appartenenti a una categoria in ordine crescente alfabetico in base al cognome

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void ordinaContatti(contatti tabella[], int N, int categorie[])
{

    // dichiarazione variabili
    int i;
    int j;
    int categoriaInput;                     // input della categoria da ordinare
    int count;                              // conteggio dei contatti appartenenti a una categoria
    bool flag;                              // il valore cambia quando viene inserita una categoria valida
    contatti categoriaScelta[CONTATTI_MAX]; // array provvisorio per memorizzare le info della categoria selezionata

    // inizializzazione variabili
    count = 0;
    flag = false;

    // input categoria
    do
    {
        cout << "\ninserisci la categoria da ORDINARE: ";
        cin >> categoriaInput;

        for (i = 0; i < CATEGORIE_MAX && flag != true; i++)
        {

            if (categorie[i] == categoriaInput)
            {
                flag = true;
            }
        }

    } while (!flag);

    // ciclo che memorizza i contatti della categoria nell'array provvisorio
    for (i = 0; i < N; i++)
    {
        if (tabella[i].categoria == categoriaInput)
        {
            categoriaScelta[count] = tabella[i];
            count++;
        }
    }

    // ciclo che fa ordinamento crescente della categoria scelta in base al cognome
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {

            if (categoriaScelta[i].congome > categoriaScelta[j].congome)
            {
                swap(categoriaScelta[i], categoriaScelta[j]);
            }
        }
    }

    // ciclo che stampa i contatti della categoria
    cout << "\n\n***STAMPA ORDINE CRESCENTE (cognome) CONTATTI CATEGORIA " << categoriaInput << " ***\n\n";
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << " CONTATTO -->  nome: " << categoriaScelta[i].nome;
        cout << "   cognome: " << categoriaScelta[i].congome;
        cout << "   N di telefono: " << categoriaScelta[i].telefono;
        cout << "   categoria: " << categoriaScelta[i].categoria << "\n\n";
    }
}