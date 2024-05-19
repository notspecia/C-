/*Un negozio di alimentari ha un archivio (tabella) in cui vengono memorizzati i prodotti
presenti in magazzino. Per ogni prodotto in magazzino, si dispone dei seguenti dati:
● la descrizione,
● la quantità disponibile in magazzino,
● la data di scadenza.
Il programma deve memorizzare in un altra tabella tutti i prodotti che sono da cancellare
dall'archivio perché scaduti (un prodotto è scaduto quando l'anno di scadenza è inferiore al 2024).*/

#include <iostream>
#include <string>
using namespace std;

const int N_MAX_PRODOTTI = 100;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct prodotto
{
    string descrizione;
    int quantita;
    int annoScadenza;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(prodotto tabella[], int N);
void eliminaTabella(prodotto tabella[], int &N);
void nuovaTabella(prodotto tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    prodotto tabella[N_MAX_PRODOTTI]; // tabella dei prodotti
    int N;                            // N di prodotti da registrare nella tabella

    // funzione che legge la quantità di prodotti da inserire
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni prodotto nella tabella
    caricaTabella(tabella, N);

    // funzione che elimina dalla tabella i prodotti scaduti (<2024)
    eliminaTabella(tabella, N);

    // funzione che stampa la nuova tabella con i prodotti validi (= 2024/ >2024)
    nuovaTabella(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge la quantità di prodotti da inserire successivamente nella tabella

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{
    do
    {
        cout << "\ninserisci quanti PRODOTTI vuoi memorizzare (0-100): ";
        cin >> N;
    } while (N <= 0 || N > N_MAX_PRODOTTI);
}

/*funzione che che memorizza le informazioni di ogni prodotto nella tabella

parametri formali:
int N, prodotto tabella[N_MAX_PRODOTTI]

valore restituito:
null
*/
void caricaTabella(prodotto tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che permette l'inserimento di un prodotto + descrizione nella tabella
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO INFORMAZIONI DEL " << i + 1 << " PRODOTTO ***\n";

        // inserimento nella tabella descrizione del prodotto
        cout << "\nDescrizione del " << i + 1 << " prodotto: ";
        cin.ignore();
        getline(cin, tabella[i].descrizione);

        // inserimento nella tabella della quantità del prodotto in magazzino
        do
        {
            cout << "Quantita di scorte in magazzino del " << i + 1 << " prodotto: ";
            cin >> tabella[i].quantita;
        } while (tabella[i].quantita <= 0);

        // inserimento della data di scadenza del prodotto (anno)
        do
        {
            cout << "Inserisci la data di scadenza del " << i + 1 << " prodotto: ";
            cin >> tabella[i].annoScadenza;
        } while (tabella[i].annoScadenza < 2000 || tabella[i].annoScadenza > 2030);
    }
}

/*funzione che elimina dalla tabella i prodotti con scadenza < 2024

parametri formali:
int &N, prodotto tabella[N_MAX_PRODOTTI]

valore restituito:
null
*/
void eliminaTabella(prodotto tabella[], int &N)
{

    // dichiarazione variabili
    int i;
    int j;

    // inizializzazione variabili
    i = 0;

    while (i < N)
    {
        if (tabella[i].annoScadenza < 2024)
        {
            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }

            N--; // decremento della quantità di prodotti
        }
        else
        {
            i++; // andiamo avanti di 1 posizione
        }
    }
}

/*funzione che stampa la nuova tabella con i prodotti validi (= 2024/ >2024)

parametri formali:
int N, prodotto tabella[N_MAX_PRODOTTI]

valore restituito:
null
*/
void nuovaTabella(prodotto tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che stampa i prodotti ancora validi
    cout << "\n\n\n\n*** STAMPA DEI PRODOTTI ANCORA VALIDI ***\n";
    for (i = 0; i < N; i++)
    {
        cout << "\nil prodotto " << tabella[i].descrizione << ", scadra nel " << tabella[i].annoScadenza << endl;
    }
}