#include <iostream>
#include <string>

#include "verifica.h"

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
    cout << "\n\n\n----------------------------------------------------------------------------------------" << endl;
    cout << "1. Inserimento di N libri nella biblioteca" << endl;
    cout << "2. Stampa del numero totale di libri presenti" << endl;
    cout << "3. Stampa di tutti i libri presenti" << endl;
    cout << "4. Stampa di tutti i libri ordinati per autore" << endl;
    cout << "5. Stampa dei libri che non sono in prestito ordinati per codice" << endl;
    cout << "6. Stampa di tutti i libri in scadenza (a meno di 2 giorni dalla data di scadenza)" << endl;
    cout << "7. Esci" << endl;
    cout << "\n\n";

    // inserimento scelta input utente
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette inserimento di N libri (max 10)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "\ninserisci il numero di libri presenti in biblioteca (max " << MAX_LIBRI << "): ";
        cin >> N;
    } while (N <= 0 || N > MAX_LIBRI);
}

/*funzione che memorizza le informazioni di ogni libro nella tabella

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void caricaTabella(libri tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che permette inserimento informazioni di ogni libro
    for (i = 0; i < N; i++)
    {
        cout << "\n\n\n*** INSERIMENTO DATI " << i + 1 << " LIBRO***\n";

        // inserimento codice del libro
        cout << "\ninserisci CODICE libro: ";
        cin >> tabella[i].codiceLibro;

        // inserimento titolo del libro
        cout << "\ninserisci TITOLO del libro: ";
        cin.ignore();
        getline(cin, tabella[i].titolo);

        // inserimento nome dell'autore
        cout << "\ninserisci NOME dell'autore: ";
        getline(cin, tabella[i].autore);

        // inserimento anno di pubblicazione del libro
        do
        {
            cout << "\ninserisci ANNO DI PUBBLICAZIONE libro: ";
            cin >> tabella[i].anno;
        } while (tabella[i].anno < 0 || tabella[i].anno > 2024);

        // inserimento della casa editrice del libro
        cout << "\ninserisci NOME DELLA CASA EDITRICE: ";
        cin.ignore();
        getline(cin, tabella[i].casaEditrice);

        // inserimento opzione se X libro è o non è in prestito
        do
        {
            cout << "\n\nlibro e in prestito 0   libro non e in prestito 1\ninserisci opzione: ";
            cin >> tabella[i].isPrestato;
        } while (tabella[i].isPrestato < 0 || tabella[i].isPrestato > 1);

        // se il libro è in prestito inserimento del nome del cliente e giorni rimasti per la scadenza
        if (tabella[i].isPrestato == 0)
        {

            cout << "\ninserisci il NOME del cliente: ";
            cin.ignore();
            getline(cin, tabella[i].nomeCliente);

            do
            {
                cout << "\ninserimento GIORNI RIMASTI per il prestito: ";
                cin >> tabella[i].giorniRimasti;
            } while (tabella[i].giorniRimasti <= 0);
        }
    }
}

/*funzione che stampa la quantità di libri (N)

parametri formali:
int N

valore restituito:
null
*/
void stampaNlibri(int N)
{
    cout << "\n\nnumero di libri presenti nella biblioteca: " << N;
}

/*funzione che stampa i libri e le sue informazioni dettagliate

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void stampaDeiLibri(libri tabella[], int N)
{
    // dichiarazione variabili
    int i;

    // ciclo che stampa tutti i libri e le loro informazioni
    cout << "\n\n***STAMPA DEI LIBRI CON INFORMAZIONI***\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " LIBRO --> codice numerico: " << tabella[i].codiceLibro;
        cout << "   titolo: " << tabella[i].titolo;
        cout << "   autore: " << tabella[i].autore;
        cout << "   anno di pubblicazione: " << tabella[i].anno;
        cout << "   casa editrice: " << tabella[i].casaEditrice;
        
        if (tabella[i].isPrestato == 0)
        {
            cout << "   nome cliente: " << tabella[i].nomeCliente;
            cout << "   giorni rimasti x prestito: " << tabella[i].giorniRimasti;
        }

        cout << "\n\n";
    }
}

/*funzione che stampa in ordine crescente per autore i libri

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void ordinaPerAutore(libri tabella[], int N)
{
    // dichiarazione variabili
    int i;
    int j;

    // ciclo che ordina in ordine crescente i libri per autore
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (tabella[i].autore > tabella[j].autore)
            {
                swap(tabella[i], tabella[j]);
            }
        }
    }

    // ciclo che stampa tutti i libri ordinati per autore
    cout << "\n\n***STAMPA DEI LIBRI IN ORDINE CRESCENTE X AUTORE***\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " LIBRO --> codice numerico: " << tabella[i].codiceLibro;
        cout << "   titolo: " << tabella[i].titolo;
        cout << "   autore: " << tabella[i].autore;
        cout << "   anno di pubblicazione: " << tabella[i].anno;
        cout << "   casa editrice: " << tabella[i].casaEditrice;
        if (tabella[i].isPrestato == 0)
        {
            cout << "   nome cliente: " << tabella[i].nomeCliente;
            cout << "   giorni rimasti x prestito: " << tabella[i].giorniRimasti;
        }

        cout << "\n\n";
    }
}

/*funzione che stampa in ordine crescente di codice i libri che NON sono in prestito

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void ordinaPerCodiceNonInPrestito(libri tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;
    int count;                   // conteggio dei libri NON in prestito
    libri noprestito[MAX_LIBRI]; // tabella provvisoria utile per lavorare con i libri non in prestito

    // inizializzazione variabili
    count = 0;

    // ciclo che memorizza i libri NON in prestito nella tabella libri noprestito[]
    for (i = 0; i < N; i++)
    {
        if (tabella[i].isPrestato == 1)
        {
            noprestito[count] = tabella[i];
            count++;
        }
    }

    // ciclo che ordina crescentemente per codice i libri presenti nell'array di supporto
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {

            if (noprestito[i].codiceLibro > noprestito[j].codiceLibro)
            {
                swap(noprestito[i], noprestito[j]);
            }
        }
    }

    // ciclo che stampa i libri presenti nell'array di supporto che sono stati ordinati per codice
    cout << "\n\n***STAMPA DEI LIBRI NON IN PRESTITO IN ORDINE CRESCENTE X CODICE***\n\n";
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << " LIBRO NON IN PRESTITO --> codice numerico: " << noprestito[i].codiceLibro;
        cout << "   titolo: " << noprestito[i].titolo;
        cout << "   autore: " << noprestito[i].autore;
        cout << "   anno di pubblicazione: " << noprestito[i].anno;
        cout << "   casa editrice: " << noprestito[i].casaEditrice;
        cout << "\n\n";
    }
}

/*funzione che stampa i libri che hanno una scadenza a meno di 2 giorni

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void stampaLibriScadenza(libri tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che stampa i libri in prestito che hanno una scadenza < di 2 giorni
    cout << "\n\n***STAMPA DEI LIBRI PRESTITO CON SCADENZA <= GIORNI***\n\n";
    for (i = 0; i < N; i++)
    {
        // se il libro è in prestito...
        if (tabella[i].isPrestato == 0 && tabella[i].giorniRimasti <= 2)
        {
            cout << i + 1 << " LIBRO SCADENZA <= 2 --> codice numerico: " << tabella[i].codiceLibro;
            cout << "   titolo: " << tabella[i].titolo;
            cout << "   autore: " << tabella[i].autore;
            cout << "   anno di pubblicazione: " << tabella[i].anno;
            cout << "   casa editrice: " << tabella[i].casaEditrice;
            cout << "   nome cliente: " << tabella[i].nomeCliente;
            cout << "   giorni rimasti x prestito: " << tabella[i].giorniRimasti;
            cout << "\n\n";
        }
    }
}

/*funzione che chiede all'utente la conferma per uscire dal programma

parametri formali:
bool uscita

valore restituito:
bool uscita
*/
bool uscitaProgramma(bool uscita)
{

    // dichiarazione variabili
    int inputUscita;

    // ciclo con verifica dell'input che chiede se uscire o rimanere nel programma + controllo
    do
    {
        cout << "\nUSCITA PROGRAMMA 1      RIMANI 0\ninserisci opzione: ";
        cin >> inputUscita;

        if (inputUscita == 1)
        {
            uscita = true;
        }

    } while (inputUscita < 0 || inputUscita > 1);

    return uscita;
}