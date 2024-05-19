/*Si scriva un programma per gestire una tabella che descrive un insieme di lattine
cilindriche atte a contenere alimenti. In particolare, ogni record sarà composto da una
stringa di descrizione del contenuto (p.e. “fagioli”), l’altezza della lattina (p.e. 12) e il raggio
della lattina (p.e. 7) entrambi in centimetri. Dopo aver fatto popolare la tabella dall’utente,
il programma richiede all’utente di scegliere le diverse elaborazioni indicate dalle seguenti
opzioni:

1. Stampa del numero di record totali inseriti
2. Ricerca di una lattina data la descrizione. (La ricerca deve essere effettuata
utilizzando l’algoritmo di ricerca dicotomico)
3. Stampa dei soli record che presentano un’altezza della lattina maggiore di un valore
inserito in input dall’utente.
4. Stampa di tutti i record ordinati per volume decrescente (Formula volume del
cilindro: 2*pigreco*raggio*altezza)
5. Uscita (con conferma)
*/

#include <iostream>
#include <string>
#define LATTINE_MAX 10 // lattine massime inseribili

using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con dati e informazioni relative alle lattine
struct lattina
{
    string descrizione;
    float altezza;
    float raggio;
    float volume;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(lattina tabella[], int N);
int leggiMenu();
void stampaRecord(int N);
void ricercaLattina(lattina tabella[], int N);
void stampaAltezzaMaggiore(lattina tabella[], int N);
void volumeCrescente(lattina tabella[], int N);
bool uscitaProgramma(bool uscita);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                        // quantità di lattine (max 10)
    lattina tabella[LATTINE_MAX]; // tabella che contiene informazioni sulle lattine
    int menu;                     // schermata del menu di scelta
    bool uscita;                  // x uscita dal programma

    // inizializzazione variabili
    uscita = false;

    // funzione che permette inserimento di N (quantità di lattine)
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni lattina nella tabella
    caricaTabella(tabella, N);

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {
        // funzione che stampa il record di lattine (N)
        case 1:
            stampaRecord(N);
            break;

        // funzione che ricerca e stampa le lattine con la descrizione data in input
        case 2:
            ricercaLattina(tabella, N);
            break;

        // funzione che stampa le lattine con una altezza > di quella data in input
        case 3:
            stampaAltezzaMaggiore(tabella, N);
            break;

        // funzione che stampa in ordine decrescente le lattinein base al loro volume
        case 4:
            volumeCrescente(tabella, N);
            break;

        // funzione che permette l'uscita dal programma con conferma
        case 5:
            uscita = uscitaProgramma(uscita);
            break;

        // se si inserisce un opzione NON valida
        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (!uscita);

    return 0;
}

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
    cout << "1. Stampa del numero di record totali inseriti." << endl;
    cout << "2. Ricerca di una lattina data la descrizione." << endl;
    cout << "3. Stampa dei soli record che presentano un’altezza della lattina > di un valore inserito in input." << endl;
    cout << "4. Stampa di tutti i record ordinati per volume decrescente" << endl;
    cout << "5. Uscita (con conferma)\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n";

    return scelta;
}

/*funzione che permette inserimento N azioni (max 10)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "inserisci il numero di lattine: ";
        cin >> N;
    } while (N <= 0 || N > LATTINE_MAX);
}

/*funzione che memorizza le informazioni di ogni lattina nella tabella

parametri formali:
lattina tabella[LATTINE_MAX], int N

valore restituito:
null
*/
void caricaTabella(lattina tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che fa inserire informazioni di ogni lattina
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI " << i + 1 << " LATTINA ***\n";

        // descrizione della lattina
        cout << "inserisci la descrizione della lattina: ";
        cin.ignore();
        getline(cin, tabella[i].descrizione);

        // altezza della lattina (cm)
        do
        {
            cout << "inserisci l'altezza della lattina: ";
            cin >> tabella[i].altezza;
        } while (tabella[i].altezza <= 0);

        // raggio della lattina (cm)
        do
        {
            cout << "inserisci il raggio della lattina: ";
            cin >> tabella[i].raggio;
        } while (tabella[i].raggio <= 0);
    }
}

/*funzione che stampa il numero di record totali inseriti

parametri formali:
int N

valore restituito:
null
*/
void stampaRecord(int N)
{
    cout << "\nnumero di record di lattine inserite: " << N;
}




/*funzione che Ricerca di una lattina data la descrizione

parametri formali:
lattina tabella[LATTINE_MAX], int N

valore restituito:
null
*/
void ricercaLattina(lattina tabella[], int N)
{

    // dichiarazione variabili
    int i;
    string inputDescrizione; // descrizione data in input dall'utente
    bool flag;               // cambia se c'è 1 o + descrizioni =

    // inizializzazione variabili
    flag = false;

    // inserimento della descrizione
    cout << "\ninserisci la descrizione dell'elemento che vuoi ricercare: ";
    cin.ignore();
    getline(cin, inputDescrizione);

    // ciclo per trovare elemento con la descrizione inserita
    cout << "\n\n***STAMPA LATTINE CON = DESCRIZIONE***\n";
    for (i = 0; i < N; i++)
    {
        if (inputDescrizione == tabella[i].descrizione)
        {
            cout << "\nlattina " << i + 1 << " con descrizione: " << inputDescrizione << " trovata!" << endl;
            flag = true;
        }
    }

    // se non ci sono descrizioni = a quella data in input
    if (flag == false)
    {
        cout << "\nlattin* con descrizione: " << inputDescrizione << " NON trovata!";
    }
}

/*funzione che stampa i record che presentano un’altezza della lattina maggiore di un valore inserito in input dall’utente.

parametri formali:
lattina tabella[LATTINE_MAX], int N

valore restituito:
null
*/
void stampaAltezzaMaggiore(lattina tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int inputAltezza; // altezza data in input dall'utente

    // inserimento dell'altezza
    do
    {
        cout << "\ninserisci l'altezza maggiore: ";
        cin >> inputAltezza;
    } while (inputAltezza <= 0);

    // ciclo per trovare i record con una altezza > di quella data in input
    cout << "\n\n***STAMPA LATTINE CON ALTEZZA >***\n";
    for (i = 0; i < N; i++)
    {
        if (tabella[i].altezza > inputAltezza)
        {
            cout << "\nla " << i + 1 << " lattina ha una altezza > di " << inputAltezza << endl;
        }
    }
}

/*funzione che stampa tutti i record ordinati per volume decrescente

parametri formali:
lattina tabella[LATTINE_MAX], int N

valore restituito:
null
*/
void volumeCrescente(lattina tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che calcola il volume di ogni lattina
    for (i = 0; i < N; i++)
    {
        tabella[i].volume = 2 * 3.14 * tabella[i].raggio * tabella[i].altezza;
    }

    // ciclo che ordina in ordine decrescente il volume delle lattine
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (tabella[i].volume < tabella[j].volume)
            {
                swap(tabella[i], tabella[j]);
            }
        }
    }

    // stampa delle lattine in ordine crescente in base al volume
    cout << "\n\n***STAMPA ORDINE DECRESCENTE LATTINE***\n\n";
    for (i = 0; i < N; i++)
    {

        cout << i + 1 << " LATTINA -->  volume: " << tabella[i].volume << endl;
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

    // ciclo che chiede se uscire o rimanere nel programma + controllo
    do
    {
        cout << "\nUSCITA PROGRAMMA 1     RIMANI 0\ninserisci opzione: ";
        cin >> inputUscita;

        if (inputUscita == 1)
        {
            uscita = true;
        }

    } while (inputUscita < 0 || inputUscita > 1);

    return uscita;
}