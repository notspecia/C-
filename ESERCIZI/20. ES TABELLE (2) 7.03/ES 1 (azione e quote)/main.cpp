/*Una tabella contiene l'andamento delle quotazioni di alcune azioni in borsa nell'ultima
settimana. La struttura è definita in questo modo: nome, valori: una sequenza di 7 float
(uno per ogni giorno della settimana).Il programma deve visualizzare sullo schermo
quante azioni hanno avuto un calo superiore al 10% in una sola giornata.
Esempio:
Stellantis 100 98 97 96 110 109 105
ACME 100 95 100 88 81 105 107
Il programma dovrà fornire come risultato 1, in quanto la ACME ha avuto un calo superiore
al 10% fra il terzo e il quarto giorno.
*/

#include <iostream>
#include <string>
using namespace std;

// costanti variabili
const int VALORI_MAX = 7;
const int N_AZIONI_MAX = 10;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struct contenente il nome delle azioni, e i valori dei x 7 giorni
struct azioni
{
    string nome;
    float valori[VALORI_MAX];
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(azioni tabella[], string settimana[], int N);
void azioneCalata(azioni tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                                                                                                         // N. di azioni (max 10)
    azioni tabella[N_AZIONI_MAX];                                                                                  // tabella che memorizza le informazioni delle azioni
    string settimana[VALORI_MAX] = {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"}; // array con giorni della settimana

    // funzione che permette inserimento N azioni (max 10)
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni azione nella tabella
    caricaTabella(tabella, settimana, N);

    // funzione che stampa quali azioni sono calate almeno 1 volta del 10% tra una giornata e l'altra
    azioneCalata(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

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
        cout << "inserisci il numero di azioni ";
        cin >> N;
    } while (N <= 0 || N > N_AZIONI_MAX);
}

/*funzione che memorizza le informazioni di ogni azione nella tabella

parametri formali:
azioni tabella[N_AZIONI_MAX], int N

valore restituito:
null
*/
void caricaTabella(azioni tabella[], string settimana[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che fa inserire informazioni di ogni azione
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI " << i + 1 << " AZIONE ***\n";

        // nome dell'azione
        cout << "inserisci il nome dello azione: ";
        cin.ignore();
        getline(cin, tabella[i].nome);

        // valori dell'azione (1 valore per ogni giorno della settimana)
        for (j = 0; j < VALORI_MAX; j++)
        {
            do
            {
                cout << "inserisci il valore di " << settimana[j] << ": ";
                cin >> tabella[i].valori[j];
            } while (tabella[i].valori[j] < 0);
        }
    }

    // stampa per avere una schermata riepiloghiva dei valori di ogni azione
    cout << "\n\n\n**RIASSUNTO DEI VALORI DELLE AZIONI**" << endl;
    for (i = 0; i < N; i++)
    {
        cout << "\n\n"
             << tabella[i].nome << " -->";

        for (j = 0; j < 7; j++)
        {
            cout << "     " << tabella[i].valori[j];
        }
    }
}

/*funzione che stampa le azioni che hanno avuto un calo del 10% tra una giornata e l'altra

parametri formali:
azioni tabella[N_AZIONI_MAX], int N

valore restituito:
null
*/
void azioneCalata(azioni tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;
    int count;   // contatore di quanti cali ha subito un'azione
    float quota; // di quanto è aumentata/diminuita la quota di un'azione

    // ciclo che calcola le quote di ogni azione giorno dopo giorno
    cout << "\n\n\n";
    for (i = 0; i < N; i++)
    {
        count = 0; // inizializzaziamo e resettiamo il conteggio ogni volta

        for (j = 1; j < 7; j++)
        {
            quota = ((tabella[i].valori[j] - tabella[i].valori[j - 1]) / tabella[i].valori[j - 1]) * 100;
            if (quota < -10)
            {
                count++;
            }
        }

        // stampa se c'è almeno un calo del 10%
        if (count > 0)
        {
            cout << "l'azione " << tabella[i].nome << ", ha avuto in totale " << count << " cali del 10% o +, fra due giornate\n"
                 << endl;
        }
    }
}