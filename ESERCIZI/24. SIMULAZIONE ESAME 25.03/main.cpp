#include "verifica.h"

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                    // quantità di libri presenti nella biblioteca
    libri tabella[MAX_LIBRI]; // tabella contenente informazioni sui vari libri
    int menu;                 // schermata del menu di scelta
    bool flag;                // il suo valore cambia se si effettua la prima opzione
    bool uscita;              // x uscita dal programma

    // inizializzazione variabili
    flag = false;
    uscita = false;

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {

        // funzione che permette inserimento di N libri e funzione che carica informazioni nella tabella
        case 1:
            inserimentoN(N);
            caricaTabella(tabella, N);
            flag = true; // ora possiamo fare tutte le altre operazioni
            break;

        // funzione che stampa la quantità di libri (N)
        case 2:
            if (flag == true)
            {
                stampaNlibri(N);
            }
            else
            {
                cout << "\nnon hai inserito nessun libro!" << endl;
            }
            break;

        // funzione che stampa nel dettaglio i libri e le sue informazioni
        case 3:
            if (flag == true)
            {
                stampaDeiLibri(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessun libro!" << endl;
            }
            break;

        // funzione che stampa in ordine crescente per autore i libri
        case 4:
            if (flag == true)
            {
                ordinaPerAutore(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessun libro!" << endl;
            }
            break;

            // funzione che stampa in ordine crescente di codice i libri che non sono in prestito
        case 5:
            if (flag == true)
            {
                ordinaPerCodiceNonInPrestito(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessun libro!" << endl;
            }
            break;

            // funzione che stampa i libri che hanno una scadenza a meno di 2 giorni
        case 6:
            if (flag == true)
            {
                stampaLibriScadenza(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessun libro!" << endl;
            }
            break;

        // funzione che chiede all'utente la conferma per uscire dal programma
        case 7:
            uscita = uscitaProgramma(uscita);
            break;

        // se si inserisce un opzione NON valida
        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (!uscita);

    return 0;
}
