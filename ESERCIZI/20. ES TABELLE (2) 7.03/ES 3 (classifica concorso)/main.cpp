/*Alla fine di un concorso vengono pubblicati i risultati delle prove dei concorrenti: vengono
memorizzati, per ogni partecipante:
● il nome,
● il punteggio della prima prova ,
● il punteggio della seconda prova.
Si vuole ottenere la graduatoria finale con la visualizzazione dei concorrenti ordinati in
modo decrescente rispetto al punteggio totale conseguito.
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// variabile globale
const int N_MAX_PARTECIPANTI = 20;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struct che contiene le 2 prove
struct risultati
{
    int primaProva;
    int secondaProva;
};


// struct con informazioni del partecipe
struct partecipante
{
    string nome;
    risultati prove; // collegamento ad una struct che ha i voti delle 2 prove
    int votoFinale;  // voto finale dato dalla somma delle 2 prove
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(partecipante tabella[], int N);
void graduatoriaFinale(partecipante tabella[], int N);
void stampaGraduatoria(partecipante tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                                    // quantità dei partecipanti
    partecipante tabella[N_MAX_PARTECIPANTI]; // tabella che memorizza informazioni partecipanti

    // funzione che permette inserimento N partecipanti (max 20)
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni partecipante nella tabella
    caricaTabella(tabella, N);

    // funzione che somma le 2 prove nel voto finale (prova1 + prova2)
    graduatoriaFinale(tabella, N);

    // funzione che stampa la graduatoria finale dei voti dei partecipanti in ordine DECRESCENTE
    stampaGraduatoria(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che permette inserimento N partecipanti (max 20)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{
    do
    {
        cout << "\ninserisci il numero dei partecipanti: ";
        cin >> N;
    } while (N <= 0 || N > N_MAX_PARTECIPANTI);
}



/*funzione che memorizza le informazioni di ogni partecipante nella tabella

parametri formali:
partecipante tabella[N_MAX_PARTECIPANTI], int N

valore restituito:
null
*/
void caricaTabella(partecipante tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo che inserisce informazioni dei partecipanti
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI DEL " << i + 1 << " PARTECIPANTE ***\n";

        // nome del partecipe
        cout << "inserisci il nome del partecipante: ";
        cin.ignore();
        getline(cin, tabella[i].nome);

        // 1 votazione del partecipante
        do
        {
            cout << "valutazione della prima prova: ";
            cin >> tabella[i].prove.primaProva;
        } while (tabella[i].prove.primaProva <= 0);

        // 2 votazione del partecipante
        do
        {
            cout << "valutazione della seconda prova: ";
            cin >> tabella[i].prove.secondaProva;
        } while (tabella[i].prove.secondaProva <= 0);
    }
}



/*funzione che somma le 2 prove nel voto finale (prova1 + prova2)

parametri formali:
partecipante tabella[N_MAX_PARTECIPANTI], int N

valore restituito:
null
*/
void graduatoriaFinale(partecipante tabella[], int N)
{

    // dichairazione variabili
    int i;

    // ciclo che memorizza la votazione finale di ogni partecipante
    for (i = 0; i < N; i++)
    {
        tabella[i].votoFinale = tabella[i].prove.primaProva + tabella[i].prove.secondaProva;
    }
}




/*funzione che ordina e stampa la graduatoria finale dei voti dei partecipanti in ordine DECRESCENTE

parametri formali:
partecipante tabella[N_MAX_PARTECIPANTI], int N

valore restituito:
null
*/
void stampaGraduatoria(partecipante tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // cicli per ordinare e creare una graduatoria finale in ordine DECRESCENTE
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (tabella[j].votoFinale < tabella[j + 1].votoFinale)
            {
                swap(tabella[j], tabella[j + 1]);
            }
        }
    }

    // ciclo per stampare la graduatoria finale
    cout << "\n\n\n*** GRADUATORIA FINALE DEI PARTECIPANTI ***\n";
    for (i = 0; i < N; i++)
    {
        cout << "\n"
             << i + 1 << " posto --> " << tabella[i].nome << ", con la valutazione finale di: " << tabella[i].votoFinale << endl;
    }
}
