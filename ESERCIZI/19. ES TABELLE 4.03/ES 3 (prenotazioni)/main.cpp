/*Un ambulatorio dentistico utilizza una tabella per memorizzare tutte le prenotazioni
effettuate per il mese di Luglio. Le prenotazioni hanno il seguente tracciato record:
cognome e data (numero compreso da 1 a 30).
Si scriva una funzione che stampi sullo standard output quali siano i giorni liberi.
Si costruisca il programma che carichi la tabella e provi la funzione progettata.*/

#include <iostream>
#include <string>
using namespace std;

const int N_MAX_PRENOTAZIONI = 100;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct prenotazione
{
    string cognome;
    int gg;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(prenotazione tabella[], int N);
void giorniLiberi(prenotazione tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                                    // quantità di prenotazioni
    prenotazione tabella[N_MAX_PRENOTAZIONI]; // inserimento delle informazioni nella tabella prenotazioni (cognome, data)

    // funzione che legge la quantità di prenotazioni x luglio
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni prenotazione nella tabella
    caricaTabella(tabella, N);

    // funzione che cambia la tabella con i giorni liberi (NO prenotati)
    giorniLiberi(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge la quantità di prenotazioni x luglio

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{
    do
    {
        cout << "\n***inserisci quante prenotazioni vuoi registrare (0-" << N_MAX_PRENOTAZIONI << "):*** ";
        cin >> N;
    } while (N <= 0 || N > N_MAX_PRENOTAZIONI);
}

/*funzione che che memorizza il cognome e la data della prenotazione di ogni cliente x luglio

parametri formali:
prodotto tabella[N_MAX_PRODOTTI], int N

valore restituito:
null
*/
void caricaTabella(prenotazione tabella[], int N)
{
    // dichiarazione variabili
    int i;

    // ciclo che permette l'inserimento di un prodotto + descrizione nella tabella
    for (i = 0; i < N; i++)
    {
        cout << "\n\n\n*** INSERIMENTO INFORMAZIONI DELLA " << i + 1 << " PRENOTAZIONE ***\n";

        // inserimento nella tabella del cognome del cliente
        cout << "\nCognome del cliente della " << i + 1 << " prenotazione: ";
        cin >> tabella[i].cognome;

        // inserimento nella tabella il giorno di luglio della prenotazione
        do
        {
            cout << "\nGiorno del cliente della " << i + 1 << " prenotazione: ";
            cin >> tabella[i].gg;

        } while (tabella[i].gg <= 0 || tabella[i].gg > 30);
    }
}

/*funzione che stampa i giorni liberi di luglio andando a confrontare quelli prenotati

parametri formali:
prenotazione tabella[], int N

valore restituito:
null
*/
void giorniLiberi(prenotazione tabella[], int N)
{
    
    // dichiarazione variabili
    int i;
    int j;
    bool esci;

    // cicli che controlla e stampa i giorni liberi
    cout << "\n\n\n***LISTA DEI GIORNI LIBERI***\n-----------\n";
    for (i = 1; i <= 30; i++)
    {
        esci = false;

        for (j = 0; j < N && esci != true; j++)
        {

            // se il giorno (i) è = ai giorni presenti nella tabella...
            if (tabella[j].gg == i)
            {
                esci = true;
            }
        }

        // stampa del giorno se è libero
        if (esci == false)
        {
            cout << i << endl;
        }
    }
    cout << "-----------" << endl;
}
