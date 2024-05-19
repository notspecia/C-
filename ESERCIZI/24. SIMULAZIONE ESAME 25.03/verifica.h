#ifndef _VERIFICA_
#define _VERIFICA_

#include <iostream>
#include <string>

#define MAX_LIBRI 10 // variabile globale libri massimi inseribili

using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura contente le informazioni sui libri
struct libri
{
    int codiceLibro;     // codice del libro
    string titolo;       // titolo del libro
    string autore;       // nome dell'autore
    int anno;            // anno di pubblicazione del libro
    string casaEditrice; // nome della casa editrice
    int isPrestato;      // se il libro è in prestito o no
    string nomeCliente;  // nome del cliente se il libro è in prestito
    int giorniRimasti;   // scadenza del libro se il libro è in prestito
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

/*funzione che apre il menu di scelta all'utente

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu();

/*funzione che permette inserimento di N libri (max 10)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N);

/*funzione che memorizza le informazioni di ogni libro nella tabella

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void caricaTabella(libri tabella[], int N);

/*funzione che stampa la quantità di libri (N)

parametri formali:
int N

valore restituito:
null
*/
void stampaNlibri(int N);

/*funzione che stampa in ordine crescente per autore i libri

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void stampaDeiLibri(libri tabella[], int N);

/*funzione che stampa in ordine crescente per autore i libri

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void ordinaPerAutore(libri tabella[], int N);

/*funzione che stampa in ordine crescente di codice i libri che NON sono in prestito

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void ordinaPerCodiceNonInPrestito(libri tabella[], int N);

/*funzione che stampa i libri che hanno una scadenza a meno di 2 giorni

parametri formali:
libri tabella[MAX_LIBRI], int N

valore restituito:
null
*/
void stampaLibriScadenza(libri tabella[], int N);

/*funzione che chiede all'utente la conferma per uscire dal programma

parametri formali:
bool uscita

valore restituito:
bool uscita
*/
bool uscitaProgramma(bool uscita);

#endif