/*Si scriva un programma C++ che permetta di gestire le squadre di un campionato di calcio.
Le squadre sono definite da queste informazioni:
● nome squadra,
● codice squadra,
● goal fatti,
● goal subiti.
Costruire un programma che stampi un menu’ di scelta che presenti le seguenti opzioni:
1. Inserimento di N squadre di calcio e dei suoi dati
2. Stampa di tutte le squadre che hanno un numero di goal maggiore di quelli subiti
3. Dato un codice di una squadra stampare tutti i dati della stessa
4. Stampa di tutte le squadre in ordine alfabetico di nome
5. Esci
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int N_MAX_SQUADRE = 100;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct lista
{
    int goalFatti;
    int goalSubiti;
};

struct squadra
{
    string nome;
    int codiceSquadra;
    lista goal;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
void inserimentoN(int &N);
void caricaTabella(squadra tabella[], int N);
void squadraControlloGoal(squadra tabella[], int N);
void squadraControlloCodice(squadra tabella[], int N);
void squadraOrdineAlfabetico(squadra tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int menu;                       // schermata del menu di scelta
    int N;                          // numero squadre di calcio
    squadra tabella[N_MAX_SQUADRE]; // tabella che memorizza i dati presenti nella struct squadra, di ogno team/squadra
    bool flag;                      // cambia se si effettua la prima opzione

    // inizializzazione variabili
    flag = false;

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {
        // funzione che permette di inserire il numero di squadre (N) e i suoi dati (tabella)
        case 1:
            inserimentoN(N);
            caricaTabella(tabella, N);
            flag = true;
            break;

        // funzione che stampa le squadre che hanno + goal fatti che goal subiti
        case 2:
            if (flag == true)
            {
                squadraControlloGoal(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito i dati delle squadre! (premi 1)" << endl;
            }
            break;

        // funzione che dato un codice di una squadra stampare tutti i dati della stessa
        case 3:
            if (flag == true)
            {
                squadraControlloCodice(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito i dati delle squadre! (premi 1)" << endl;
            }
            break;

        // funzione che stampa tutte le squadre in ordine alfabetico di nome
        case 4:
            if (flag == true)
            {
                squadraOrdineAlfabetico(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito i dati delle squadre! (premi 1)" << endl;
            }
            break;

        // funzione per uscire dal programma
        case 5:

            break;

        // se si inserisci un'opzione non valida
        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (menu != 5);

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

    // dichiarazione variabile
    int scelta;

    // schermata menu
    cout << "\n\n\n---------------------------------------------------------" << endl;
    cout << "1. Inserimento di N squadre di calcio e dei suoi dati" << endl;
    cout << "2. Stampa di tutte le squadre che hanno un numero di goal maggiore di quelli subiti" << endl;
    cout << "3. Dato un codice di una squadra stampare tutti i dati della stessa" << endl;
    cout << "4. Stampa di tutte le squadre in ordine alfabetico di nome" << endl;
    cout << "5. Esci\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette di inserire il numero di squadre

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{
    do
    {
        cout << "quante squadre vuoi inserire? (0-100): ";
        cin >> N;
    } while (N <= 0 || N > N_MAX_SQUADRE);
}

/*funzione che permette di inserire i dati della squadra

parametri formali:
squadra tabella[], int N

valore restituito:
null
*/
void caricaTabella(squadra tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che fa inserire i dati di ogni squadra
    for (i = 0; i < N; i++)
    {
        cout << "\n\n *** INSERIMENTO DATI " << i + 1 << " SQUADRA ***\n";

        // inserimento nella tabella il nome della squadra
        cout << "\nNome della " << i + 1 << " squadra: ";
        cin.ignore();
        getline(cin, tabella[i].nome);

        // inserimento nella tabella del codice della squadra
        cout << "Codice della " << i + 1 << " squadra: ";
        cin >> tabella[i].codiceSquadra;

        // inserimento nella tabella dei goal fatti della squadra
        do
        {
            cout << "Goal FATTI dalla " << i + 1 << " squadra: ";
            cin >> tabella[i].goal.goalFatti;
        } while (tabella[i].goal.goalFatti <= 0);

        // inserimento nella tabella dei goal subiti dalla squadra
        do
        {
            cout << "Goal SUBITI dalla " << i + 1 << " squadra: ";
            cin >> tabella[i].goal.goalSubiti;
        } while (tabella[i].goal.goalSubiti <= 0);
    }
}

/*funzione che stampa le squadre che hanno fatto + goal che subiti

parametri formali:
squadra tabella[], int N

valore restituito:
null
*/
void squadraControlloGoal(squadra tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che controlla i goal fatti e subiti di tutte le squadre
    for (i = 0; i < N; i++)
    {

        // se i goal fatti sono > a quelli subiti
        if (tabella[i].goal.goalFatti > tabella[i].goal.goalSubiti)
        {
            cout << "\nla squadra " << tabella[i].nome << " ha + goal FATTI (" << tabella[i].goal.goalFatti << ") che subiti (" << tabella[i].goal.goalSubiti << ")";
        }
    }
    cout << endl;
}

/*funzione che confronta i codici della squadra con quello inserito dall'utente

parametri formali:
squadra tabella[], int N

valore restituito:
null
*/
void squadraControlloCodice(squadra tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int codice;

    // inserimento user codice
    cout << "inserisci il CODICE DELLA SQUADRA, per visualizzare i suoi dati: ";
    cin >> codice;

    // ciclo che verifica se il codice corrisponde ai codici delle squadre
    for (i = 0; i < N; i++)
    {
        if (tabella[i].codiceSquadra == codice)
        {
            cout << "\n\n*** VISUALIZZAZIONE DATI SQUADRA CON CODICE " << tabella[i].codiceSquadra << "***\n";
            cout << "\nNome Squadra: " << tabella[i].nome << endl;
            cout << "Codice Squadra: " << tabella[i].codiceSquadra << endl;
            cout << "Goal Fatti dalla squadra: " << tabella[i].goal.goalFatti << endl;
            cout << "Goal Subiti dalla squadra: " << tabella[i].goal.goalSubiti << endl;
        }
    }
}

/*funzione che stampa le squadre in ordine alfabetico

parametri formali:
squadra tabella[], int N

valore restituito:
null
*/
void squadraOrdineAlfabetico(squadra tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che swappa la posizione in base all'ordine alfabetico
    cout << "\n*** VISUALIZZAZIONE NOMI SQUADRE ORDINE ALFABETICO***" << endl;
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (tabella[j].nome > tabella[j + 1].nome)
            {
                swap(tabella[j], tabella[j + 1]);
            }
        }
    }

    // ciclo che stampa i nomi delle squadre in ordine alfabetico
    for (i = 0; i < N; i++)
    {
        cout << tabella[i].nome << endl;
    }
}
