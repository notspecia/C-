/*Un’agenzia immobiliare ha la necessità di creare un archivio per memorizzare i dati delle
case che vendono o affittano. Ogni casa è caratterizzata da una superficie (intero) in metri
quadri, dalla classe energetica (definita da una lettera, dove la A rappresenta la casa a
minor consumo energetico la F quella a maggior consumo), dal costo in migliaia di euro e
dall’indicazione se in vendita o in affitto.
Si vuole costruire un programma che mostri un menu’ di scelta con le seguenti opzioni:
1. Inserimento di una casa
2. Stampa di tutte le case
3. Stampa delle case in affitto ordinate per classe energetica (crescente)
4. Stampa delle case comprese tra due prezzi dati in input
5. Uscita*/

#include <iostream>
#include <string>
#define MAX_CASE 10

using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con dati e informazioni relative
struct casa
{
    int superficie;
    char classeEnergetica;
    double costo;
    int affittoOvedita;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
void caricaTabella(casa tabella[], int &N);
void stampaCase(casa tabella[], int N);
void ordineCrescenteAffitto(casa tabella[], int N);
void stampaCaseCompresePrezzi(casa tabella[], int N);
bool uscitaProgramma(bool uscita);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                  // quantità di case (il suo valore cresce man mano viene effetuata operazione 1)
    casa tabella[MAX_CASE]; // tabella contenente informazioni relative alle case
    int menu;               // schermata del menu di scelta
    bool flag;              // il suo valore cambia se si effettua la prima opzione
    bool uscita;            // x uscita dal programma

    // inizializzazione variabili
    N = 0;
    flag = false;
    uscita = false;

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {

        // funzione che carica tabella con informazioni e dati sulle case
        case 1:
            caricaTabella(tabella, N);
            flag = true; // ora possiamo utilizzare tutte le altre opzioni
            break;

        // funzione che stampa le informazioni delle case
        case 2:
            if (flag == true)
            {
                stampaCase(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito " << endl;
            }
            break;

        // funzione che stampa le informazioni delle case in affito in ordine crescente per classe energetica
        case 3:
            if (flag == true)
            {
                ordineCrescenteAffitto(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito " << endl;
            }
            break;

        // funzione che stampa le informazioni delle case che hanno un prezzo compreso tra 2 dati in input
        case 4:
            if (flag == true)
            {
                stampaCaseCompresePrezzi(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito " << endl;
            }
            break;

        // funzione che chiede all'utente se vuole confermare l'uscita dal programma
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
    cout << "1. Inserimento di una casa" << endl;
    cout << "2. Stampa di tutte le case" << endl;
    cout << "3. Stampa delle case in affitto ordinate per classe energetica (crescente)" << endl;
    cout << "4. Stampa delle case comprese tra due prezzi dati in input" << endl;
    cout << "5. Uscita con conferma" << endl;
    cout << "\n\n";

    // inserimento scelta input utente
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che carica tabella con informazioni e dati sulle case

parametri formali:
casa tabella[], int &N

valore restituito:
null
*/
void caricaTabella(casa tabella[], int &N)
{

    // controllo che non si superi il limite massimo di case (10)
    if (N < MAX_CASE)
    {
        cout << "\n\n*** INSERIMENTO DATI " << N + 1 << "  CASA***\n";

        // inserimento superficie della casa
        do
        {
            cout << "\ninserisci la SUPERFICIE della casa (mq): ";
            cin >> tabella[N].superficie;
        } while (tabella[N].superficie <= 0);

        // inserimento della classe energetica a cui appartiene la casa
        do
        {
            cout << "\ninserisci la CLASSE ENERGETICA della casa: ";
            cin >> tabella[N].classeEnergetica;
            tabella[N].classeEnergetica = toupper(tabella[N].classeEnergetica);
        } while (tabella[N].classeEnergetica < 'A' || tabella[N].classeEnergetica > 'F');

        // inserimento del costo della casa
        do
        {
            cout << "\ninserisci il costo della casa: ";
            cin >> tabella[N].costo;
        } while (tabella[N].costo < 1000);

        // inserimento informazione se la casa è in vendita oppure è in affitto
        do
        {
            cout << "\ncasa e in VENDITA 0   casa e in AFFITTO 1\ninserisci opzione: ";
            cin >> tabella[N].affittoOvedita;
        } while (tabella[N].affittoOvedita < 0 || tabella[N].affittoOvedita > 1);

        // incremento del numero di case
        N++;
    }

    // se si supera il numero massimo di case registrabili
    else
    {
        cout << "\nnumero - MAX superato!";
    }
}

/*funzione che stampa le informazioni delle case

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void stampaCase(casa tabella[], int N)
{
    // dichiarazione variabili
    int i;

    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " CASA -->  superficie: " << tabella[i].superficie << " mq";
        cout << "   classe energetica: " << tabella[i].classeEnergetica;
        cout << "   costo: " << tabella[i].costo;
        if (tabella[i].affittoOvedita == 0)
        {
            cout << "   contratto: vendita\n\n";
        }
        else
        {
            cout << "   contratto: affitto\n\n";
        }
    }
}

/*funzione che stampa le informazioni delle case in affito in ordine crescente per classe energetica

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void ordineCrescenteAffitto(casa tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;
    int count;
    casa affitto[MAX_CASE];

    // inizializzazione variabili
    count = 0;

    // ciclo che memorizza le case in affito nella tabella provvisoria della funzione
    for (i = 0; i < N; i++)
    {
        if (tabella[i].affittoOvedita == 1)
        {
            affitto[count] = tabella[i];
            count++;
        }
    }

    // ciclo che ordina in modo crescente le case in affito
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (affitto[i].classeEnergetica > affitto[j].classeEnergetica)
            {
                swap(affitto[i], affitto[j]);
            }
        }
    }

    // ciclo che stampa le case in affito della tabella provvisoria ordinate in ordine crescente
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << " CASA -->  superficie: " << affitto[i].superficie << " mq";
        cout << "   classe energetica: " << affitto[i].classeEnergetica;
        cout << "   costo: " << affitto[i].costo;
        cout << "   contratto: affitto\n\n";
    }
}

/* funzione che stampa le informazioni delle case che hanno un prezzo compreso tra 2 dati in input

parametri formali:
casa tabella[], int N

valore restituito:
null
*/
void stampaCaseCompresePrezzi(casa tabella[], int N)
{

    // dichiarazione variabili
    int i;
    double prezzo1;
    double prezzo2;

    // inserimento dei 2 prezzi in input
    do
    {
        cout << "\ninserisci il 1 prezzo: ";
        cin >> prezzo1;
    } while (prezzo1 < 0);

    do
    {
        cout << "\ninserisci il 2 prezzo: ";
        cin >> prezzo2;
    } while (prezzo2 < 0);

    // algoritmo di swap dei 2 prezzi utile se prezzo 2 è < di prezzo 1
    if (prezzo2 < prezzo1)
    {
        swap(prezzo2, prezzo1);
    }

    // ciclo che stampa le informazioni delle case se il loro prezzo è compreso tra i 2 prezzi dati in input
    cout << "\n\n***STAMPA CASE COMPRESE TRA " << prezzo1 << " / " << prezzo2 << "euro***\n\n";
    for (i = 0; i < N; i++)
    {
        if (tabella[i].costo > prezzo1 && tabella[i].costo < prezzo2)
        {
            cout << i + 1 << " CASA -->  superficie: " << tabella[i].superficie << " mq";
            cout << "   classe energetica: " << tabella[i].classeEnergetica;
            cout << "   costo: " << tabella[i].costo;
            if (tabella[i].affittoOvedita == 0)
            {
                cout << "   contratto: vendita\n\n";
            }
            else
            {
                cout << "   contratto: affitto\n\n";
            }
        }
    }
}

/*funzione che chiede all'utente se vuole confermare l'uscita dal programma

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