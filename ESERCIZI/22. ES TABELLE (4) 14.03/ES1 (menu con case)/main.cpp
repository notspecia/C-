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
5. Uscita
*/

#include "case.h"

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int menu;                                                            // schermata del menu di scelta
    casa tabella[N_MAX_CASE];                                            // tabella che contiene le informazioni sulle case
    int N;                                                               // tiene conto delle case inserite
    char classeEnergetiche[energetica] = {'A', 'B', 'C', 'D', 'E', 'F'}; // array che contiene le classi energetiche
    bool flag;                                                           // cambia se si effettua la prima opzione

    // inizializzazione variabili + seme casuale per numeri randomici
    flag = false;
    N = 0;
    srand(time(NULL));

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {
        // funzione che permette inserimento di una casa
        case 1:
            inserimentoCasa(tabella, N, classeEnergetiche);
            flag = true;
            break;

        // funzione che stampa tutte le case e le sue informazioni
        case 2:
            if (flag == true)
            {
                stampaCase(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna casa! (operazione 1)" << endl;
            }
            break;

        // funzione che stampa le case in AFFITTO in ordine di classe energetica
        case 3:
            if (flag == true)
            {
                stampaCaseAffitto(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna casa! (operazione 1)" << endl;
            }
            break;

        // funzione che stampa le case comprese tra due prezzi dati in input
        case 4:
            if (flag == true)
            {
                stampaCasePrezzo(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessuna casa! (operazione 1)" << endl;
            }
            break;

        // uscita dal programma
        case 5:
            break;

        // se si inserisce un opzione NON valida
        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (menu != 5);

    return 0;
}

