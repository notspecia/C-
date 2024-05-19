/*Si vuole gestire una rubrica telefonica, i contatti sono definiti dalle seguenti informazioni:
nome, cognome, numero di telefono e categoria. Costruire un programma che stampi un
menu’ di scelta che presenti le seguenti opzioni:
1. Inserimento di N contatti
2. Stampa dei contatti presenti
3. Eliminazione dei contatti appartenenti a una categoria (data in input)
4. Stampa ordinata alfabeticamente per cognome dei contatti appartenenti a una categoria (data in input)
5. Uscita*/


#include "contatti.h"


/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int menu;                                       // schermata del menu di scelta
    bool flag;                                      // il suo valore cambia se si effettua la prima opzione
    int N;                                          // tiene conto del numero di contatti inseriti
    int categorie[CATEGORIE_MAX] = {1, 2, 3, 4, 5}; // array con le varie categorie
    contatti tabella[CONTATTI_MAX];                 // tabella contenente le informazioni sui contatti

    // inizializzazione variabili + seme casuale per numeri randomici
    N = 0;
    flag = false;
    srand(time(NULL));

    // menù di scelta che contiene varie funzioni
    do
    {
        // funzione che legge il menu di scelta
        menu = leggiMenu();

        switch (menu)
        {
        // funzione che permette inserimento di contatti
        case 1:
            inserimentoContatti(tabella, N, categorie);
            flag = true;
            break;

        // funzione che stampa tutti i contatti
        case 2:
            if (flag == true)
            {
                stampaContatti(tabella, N);
            }
            else
            {
                cout << "\nnon hai inserito nessun contatto!" << endl;
            }
            break;

        // funzione che elimina i contatti appartenenti ad una categoria
        case 3:
            if (flag == true)
            {
                cancellaContatti(tabella, N, categorie);
            }
            else
            {
                cout << "\nnon hai inserito nessun contatto!" << endl;
            }
            break;

        // funzione che ordina e stampa i contatti appartenenti a una categoria in ordine crescente alfabetico in base al cognome
        case 4:
            if (flag == true)
            {
                ordinaContatti(tabella, N, categorie);
            }
            else
            {
                cout << "\nnon hai inserito nessun contatto!" << endl;
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

