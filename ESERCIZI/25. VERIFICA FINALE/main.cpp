#include "verifica.h"

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int menu;                           // schermata del menu di scelta
    int N;                              // quantità di automobili presenti
    automobile tabella[MAX_AUTOMOBILI]; // tabella contenente informazioni relative alle automobili
    bool uscita;                        // x uscita dal programma con richiesta conferma

    // inizializzazione variabili
    N = 0; // partiamo da 0 macchine registrate, il suo valore aumenta di +1 ad ogni inserimento, e diminuisce -1 a ogni cancellazione
    uscita = false;

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che mostra il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {

        // funzione che permette inserimento di un'automobile
        case 1:
            inserimentoAutomobili(tabella, N);
            break;

        // funzione che stampa sia le auto non vendute, che quelle già vendute (tutte le loro informazioni)
        case 2:
            if (N > 0)
            {
                stampaAutomobili(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna automobile!!" << endl;
            }
            break;

        // funzione che stampa le automobili non vendute e le loro informazioni
        case 3:
            if (N > 0)
            {
                stampaAutomobiliNoVendute(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna automobile!!" << endl;
            }
            break;

        // funzione che stampa e ordina crescentemente x marca le automobili vendute e le loro informazioni
        case 4:
            if (N > 0)
            {
                stampaAutomobiliVendutaMarca(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna automobile!!" << endl;
            }
            break;

        // funzione che stampa le automobili (sia vendute che non) che hanno una cilindrata > di una data in input dall'utente
        case 5:
            if (N > 0)
            {
                stampaAutomobiliCilindrataAlta(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna automobile!!" << endl;
            }
            break;

        // funzione che cancella PERMANENTEMENTE le automobili vendute prima dell'annata data in input dall'utente
        case 6:
            if (N > 0)
            {
                cancellaAutomobiliAnnoVenditaMinore(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna automobile!!" << endl;
            }
            break;

        // funzione che chiede all'utente se vuole confermare l'uscita dal programma
        case 7:
            uscita = uscitaProgramma(uscita);
            break;

        // se si inserisce un opzione NON VALIDA
        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (!uscita);

    return 0;
}