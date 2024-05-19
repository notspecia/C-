/*Un’applicazione di gestione magazzino lancia periodicamente una procedura di
aggiornamento dei propri archivi che esegue due operazioni:
1. eliminazione dei prodotti scaduti
2. aggiornamento del prezzo di prodotti di una particolare categoria merceologica

I prodotti scaduti vengono individuati se un’apposito flag è inizializzato a TRUE. Una volta
individuati devono essere eliminati e l’intero archivio deve essere compattato in maniera
tale che non vi siano posizioni vuote nella tabella. La regola di compattazione deve essere
lo “shiftamento in basso”.

L’aggiornamento del prezzo avviene chiedendo in input l’incremento/decremento del
prezzo e la categoria merceologica interessata.
Una volta eseguite le due funzionalità la procedura deve effettuare la stampa di tutti i
prodotti stampando i seguenti dati:
● Codice prodotto
● Categoria merceologica
● Prezzo

La stampa deve essere ordinata per ordine di categoria merceologica crescente e di
prezzo decrescente.
Si determini l’appropriata struttura dati necessaria a descrivere il dato trattato.
La parte di input dati può essere codificata direttamente all’interno del codice.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define CATEGORIE_MAX 5        // categorie massime disponibili
#define PRODOTTI_MAX 10        // N massimo di prodotti
#define SCADENZA_UNIVERSALE 25 // dopo il 25 gg di ottobre, i prodotti scadono
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura contente informazioni sui prodotti
struct prodotti
{
    int giornoScadenza;
    int codice;
    int categoriaMerce;
    float prezzo;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(prodotti tabella[], int N, int categorie[]);
void cancellaProdottiScaduti(prodotti tabella[], int &N);
void aggiornaPrezzoCategoria(prodotti tabella[], int N, int categorie[]);
void stampaProdottiCategoria(prodotti tabella[], int N);
void stampaProdottiPrezzo(prodotti tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                                          // quantità di prodotti (può diminuire se il prodotto è scaduto)
    prodotti tabella[PRODOTTI_MAX];                 // tabella che contiene i prodotti e i suoi dati
    int categorie[CATEGORIE_MAX] = {1, 2, 3, 4, 5}; // array contenente le categorie

    // seme randomico per numeri casuali
    srand(time(NULL));

    // funzione che inserisce la quantità di prodotti
    inserimentoN(N);

    // funzione che carica la tabella con le informazioni dei prodotti
    caricaTabella(tabella, N, categorie);

    // funzione che cancella i prodotti scaduti dalla tabella
    cancellaProdottiScaduti(tabella, N);

    // funzione che aggiorna i prezzi di una categoria
    aggiornaPrezzoCategoria(tabella, N, categorie);

    // funzione che stampa i prodotti in ordine crescente in base alla categoria
    stampaProdottiCategoria(tabella, N);

    // funzione che stampa i prodotti in ordine decrescente in base al prezzo
    stampaProdottiPrezzo(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che chiede di inserire la quantità di prodotti (max10)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "\ninserisci il numero di prodotti (max " << PRODOTTI_MAX << "): ";
        cin >> N;
    } while (N <= 0 || N > PRODOTTI_MAX);
}

/*funzione che memorizza informazioni di ogni prodotto nella tabella prodotti

parametri formali:
prodotti tabella[], int N, int categorie[]

valore restituito:
null
*/
void caricaTabella(prodotti tabella[], int N, int categorie[])
{

    // dichiarazione variabili
    int i;
    int j;
    bool flag; // valore cambia se la categoria della merce è valida

    // ciclo che fa inserire informazioni di ogni prodotto
    for (i = 0; i < N; i++)
    {
        // reset per il controllo della categoria
        flag = false;

        cout << "\n\n\n*** INSERIMENTO DATI " << i + 1 << " PRODOTTO ***\n";

        // data di scadenza del prodotto
        do
        {
            cout << "\ninserisci il giorno di scadenza (ottobre): ";
            cin >> tabella[i].giornoScadenza;
        } while (tabella[i].giornoScadenza <= 0 || tabella[i].giornoScadenza > 31);

        // codice del prodotto RANDOMICO
        tabella[i].codice = 110 + (rand() % (240 - 110));
        cout << "\ninserisci il codice del libro: " << tabella[i].codice << endl;

        // categorie merce del prodotto
        do
        {
            cout << "\ninserisci categoria della merce (1-5): ";
            cin >> tabella[i].categoriaMerce;

            for (j = 0; j < CATEGORIE_MAX; j++)
            {
                if (tabella[i].categoriaMerce == categorie[j])
                {
                    flag = true;
                    break;
                }
            }
        } while (!flag);

        // costo del prodotto
        do
        {
            cout << "\nprezzo del prodotto: ";
            cin >> tabella[i].prezzo;
        } while (tabella[i].prezzo <= 0);
    }
}

/*funzione che che cancella i prodotti scaduti dalla tabella

parametri formali:
prodotti tabella[], int &N

valore restituito:
null
*/
void cancellaProdottiScaduti(prodotti tabella[], int &N)
{

    // dichiarazione variabili
    int i;
    int j;

    // inizializzazione variabili
    i = 0;

    // ciclo per controllare che il prodotto sia scaduto o ancora valido
    cout << "\n\n--------------******CONTROLLO SE CI SONO PRODOTTI SCADUTI, ATTENDERE...******--------------\n";

    while (i < N)
    {
        if (tabella[i].giornoScadenza >= SCADENZA_UNIVERSALE)
        {
            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }
            N--; // decremento del numero di prodotti e cancellazione del prodotto
        }
        else
        {
            i++; // andiamo avanti di 1 posizione
        }
    }
}

/*funzione che aggiorna i prezzi di una categoria inserita in input

parametri formali:
prodotti tabella[], int N

valore restituito:
null
*/
void aggiornaPrezzoCategoria(prodotti tabella[], int N, int categorie[])
{

    // dichiarazione variabili
    int categoriaInput;  // categoria inserita dall'utente
    bool flag;           // cambia il valore nel momento in cui si inserisce un input valido
    bool esiste;         // cambia il valore se esiste almeno un prodotto con la categoria in input
    int variazione;      // indica se il prezzo vecchio è < o > di quello nuovo
    float prezzoVecchio; // prende il valore del prezzo vecchio per tenerne traccia
    int i;

    // inizializzazione variabili
    flag = false;
    esiste = false;

    // input categoria + controllo che la categoria sia corretta
    do
    {
        cout << "\n\n\n\ninserisci la categoria da modificare: ";
        cin >> categoriaInput;

        for (i = 0; i < CATEGORIE_MAX && !flag; i++)
        {
            if (categoriaInput == categorie[i])
            {
                flag = true;
            }
        }
    } while (!flag);

    // ciclo con modifica dei prezzi della categoria inserita
    for (i = 0; i < N; i++)
    {
        // se il prodotto è corrispettivo alla categoria inserita...
        if (tabella[i].categoriaMerce == categoriaInput)
        {
            esiste = true;
            prezzoVecchio = tabella[i].prezzo; // diamo alla variabile prezzo vecchio il prezzo attuale dalla tabella
            cout << "\n\n*** MODIFCA PREZZO " << i + 1 << " PRODOTTO ***\n";

            // dire se il NUOVO prezzo aumenta o decrementa rispetto a quello attuale
            cout << "\nil prezzo AUMENTA 0     il prezzo DIMINUISCE 1" << endl;
            do
            {
                cout << "\ninserisci l'opzione: ";
                cin >> variazione;
            } while (variazione < 0 || variazione > 1);

            // inserimento del nuovo prezzo che INCREMENTA
            if (variazione == 0)
            {
                do
                {
                    cout << "\ninserisci il nuovo prezzo (>): ";
                    cin >> tabella[i].prezzo;
                } while (tabella[i].prezzo < prezzoVecchio);
            }
            // inserimento del nuovo prezzo che DECREMENTA
            else
            {
                do
                {
                    cout << "\ninserisci il nuovo prezzo (<): ";
                    cin >> tabella[i].prezzo;
                } while (tabella[i].prezzo > prezzoVecchio);
            }
        }
    }

    // se non c'è nessuna categoria con input
    if (!esiste)
    {
        cout << "\nnon esiste nessun prodotto con categoria " << categoriaInput << endl;
    }
}

/*funzione che stampa i prodotti in ordine crescente in base alla categoria

parametri formali:
prodotti tabella[], int N

valore restituito:
null
*/
void stampaProdottiCategoria(prodotti tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che ordina in ordine crescente in base ala categoria
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (tabella[j].categoriaMerce > tabella[j + 1].categoriaMerce)
            {
                swap(tabella[j], tabella[j + 1]);
            }
        }
    }

    // ciclo di stampa in ordine crescente in base alla categoria
    cout << "\n\n\n\n*****STAMPA DATI DEI PRODOTTI PER CATEGORIA CRESCENTE*****\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " PRODOTTO -->  codice: " << tabella[i].codice;
        cout << "  categoria: " << tabella[i].categoriaMerce;
        cout << "  prezzo: " << tabella[i].prezzo << "\n\n";
    }
}

/*funzione che stampa i prodotti in ordine decrescente in base al prezzo

parametri formali:
prodotti tabella[], int N

valore restituito:
null
*/
void stampaProdottiPrezzo(prodotti tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che ordina in ordine crescente in base ala categoria
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (tabella[i].prezzo < tabella[j].prezzo)
            {
                swap(tabella[i], tabella[j]);
            }
        }
    }

    // ciclo di stampa in ordine decrescente in base al prezzo
    cout << "\n\n\n\n*****STAMPA DATI DEI PRODOTTI PER PREZZO DECRESCENTE*****\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " PRODOTTO -->  codice: " << tabella[i].codice;
        cout << "  categoria: " << tabella[i].categoriaMerce;
        cout << "  prezzo: " << tabella[i].prezzo << "\n\n";
    }
}