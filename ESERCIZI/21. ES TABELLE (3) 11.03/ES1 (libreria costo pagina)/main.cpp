/*Una rivendita di libri usati descrive i propri prodotti secondo le seguenti caratteristiche:
● codice numerico (numero intero)
● numero di pagine
● costo
Per questioni commerciali si ha la necessità di raccogliere in un’archivio tutti i libri in
vendita e si vuole la stampa di questi secondo l’ordine crescente di costo per pagina.*/


#include "libri.h"


/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                    // quantità di libri
    libri tabella[LIBRI_MAX]; // tabella che memorizza le informazioni dei libri

    // funzione che chiede di inserire la quantità dei libri presenti nell'archivio
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni libro nella tabella
    caricaTabella(tabella, N);

    // funzione che calcola il prezzo per pagina di ogni libro
    prezzoPagina(tabella, N);

    // funzione che stampa in ordine CRESCENTE il prezzo x pagina di ogni libro
    stampaPagina(tabella, N);

    return 0;
}

