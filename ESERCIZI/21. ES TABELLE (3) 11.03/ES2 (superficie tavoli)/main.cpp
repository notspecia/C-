/*Un mobilificio deve gestire la vendita di tavoli prodotti dai diversi mastri artigiani loro fornitori.
Ogni tavolo è di una tipologia, ha un numero massimo di persone che possono
stare sedute intorno, ha delle dimensioni (altezza da terra, lunghezza e larghezza del
piano) in metri.
Si vuole creare un programma che permetta di memorizzare tutte le diverse tipologie di
tavolo che il mobilificio vende, tale applicativo deve permettere la stampa dei tavoli a
seconda del mastro artigiano inserito nella query di ricerca, ordinata per la superficie
media a persona che il tavolo può offrire.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_TAVOLI = 10;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struct che contiene le varie dimensioni del tavolo
struct dimensioni
{
    float altezza;
    float lunghezza;
    float larghezza;
};

// struct con informazioni relative ai tavoli
struct tavolo
{
    int Npersone;
    dimensioni misure;
    float superficie;
    float superficieXpersona;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/


void inserimentoN(int &N);
void caricaTabella(tavolo tabella[], int N);
void calcoloSuperficie(tavolo tabella[], int N);
void superficieMedia(tavolo tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                      // indica la quantità di tavoli da registrare
    tavolo tabella[MAX_TAVOLI]; // memorizza informazioni di ogni tavolo

    // funzione che chiede di inserire la quantità dei libri presenti nell'archivio
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni libro nella tabella
    caricaTabella(tabella, N);

    // funzione che calcola superficie totale di ogni tavolo e la sua superficie media per persona
    calcoloSuperficie(tabella, N);

    // funzione che ordina e stampa in ordine crescente in base alla superficie media per persona
    superficieMedia(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che chiede di inserire la quantità di tavoli presenti nel mobilificio

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "\ninserisci il numero di tavoli presenti nel mobilificio: ";
        cin >> N;
    } while (N <= 0 || N > MAX_TAVOLI);
}




/*funzione che memorizza le informazioni relative ai tavoli nella apposita tabella

parametri formali:
tavolo tabella[MAX_TAVOLI], int N

valore restituito:
null
*/
void caricaTabella(tavolo tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che fa inserire informazioni di ogni tavolo
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI " << i + 1 << " TAVOLO ***\n";

        // inserimento del numero massimo di spazio per persone
        do
        {
            cout << "N massimo di persone che possono sedersi: ";
            cin >> tabella[i].Npersone;
        } while (tabella[i].Npersone <= 0);

        // inserimento delle varie misure del tavolo in float (altezza, lunghezza, larghezza)

        // altezza
        do
        {
            cout << "inserisci l'altezza del tavolo (m): ";
            cin >> tabella[i].misure.altezza;
        } while (tabella[i].misure.altezza <= 0);

        // lunghezza
        do
        {
            cout << "inserisci la lunghezza del tavolo (m): ";
            cin >> tabella[i].misure.lunghezza;
        } while (tabella[i].misure.lunghezza <= 0);

        // larghezza
        do
        {
            cout << "inserisci la larghezza del tavolo (m): ";
            cin >> tabella[i].misure.larghezza;
        } while (tabella[i].misure.larghezza <= 0);
    }
}




/*funzione che calcola superficie totale di ogni tavolo e la sua superficie media per persona

parametri formali:
tavolo tabella[MAX_TAVOLI], int N

valore restituito:
null
*/
void calcoloSuperficie(tavolo tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che calcola la superficie di ogni tavolo e la sua superficie media per persona
    for (i = 0; i < N; i++)
    {
        tabella[i].superficie = (tabella[i].misure.larghezza * tabella[i].misure.lunghezza);
        tabella[i].superficieXpersona = tabella[i].superficie / tabella[i].Npersone;
    }
}




/*funzione che ordina e stampa in ordine crescente in base alla superficie media per persona

parametri formali:
tavolo tabella[MAX_TAVOLI], int N

valore restituito:
null
*/
void superficieMedia(tavolo tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // cicli che ordinano in ordine crescente in base alla superficie media
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (tabella[j].superficieXpersona > tabella[j + 1].superficieXpersona)
            {
                swap(tabella[j], tabella[j + 1]);
            }
        }
    }

    // ciclo stampa superficie medie x per persona di ogni tavolo
    cout << "\n\n\n\n*** LISTA SUPERFICIE X PERSONA DEI TAVOLI***\n";
    for (i = 0; i < N; i++)
    {
        cout << "\ntavolo con superficie --> " << tabella[i].superficie << ", superficie media x persona --> " << tabella[i].superficieXpersona << " (" << tabella[i].Npersone << " persone)" << endl;
    }
}
