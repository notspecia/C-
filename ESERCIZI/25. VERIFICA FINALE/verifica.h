#ifndef _VERIFICA_
#define _VERIFICA_

#include <iostream>
#include <string>
using namespace std;

#define MAX_AUTOMOBILI 10 // variabile globale contenente il numero massimo di auto memorizzabili

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con dati e informazioni relative all'acquirente dell'automobile
struct acquirente
{
    string nome;
    string cognome;
};

// struttura con dati e informazioni relative all'automobile
struct automobile
{
    string marca;             // marca dell'automobile
    int cilindrata;           // cilindrata dell'automobile (minimo 500)
    int annoImmatricolazione; // anno di quando la macchina è stata immatricolata
    int isVenduta;            // informazione se la macchina è stata venduta
    int annoVendita;          // anno di vendita della macchina se è stata venduta
    acquirente cliente;       // dati e informazioni relative all'acquirente
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

/*funzione che permette inserimento di un'automobile

parametri formali:
automobile tabella[], int &N

valore restituito:
null
*/
void inserimentoAutomobili(automobile tabella[], int &N);

/*funzione che stampa sia le auto non vendute, che quelle già vendute (tutte le loro informazioni)

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobili(automobile tabella[], int N);

/*funzione che stampa le automobili non vendute e le loro informazioni

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliNoVendute(automobile tabella[], int N);

/*funzione che stampa e ordina crescentemente le automobili vendute e le loro informazioni

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliVendutaMarca(automobile tabella[], int N);

/*funzione che stampa le automobili (sia vendute che non) che hanno una cilindrata > di una data in input dall'utente

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliCilindrataAlta(automobile tabella[], int N);

/*funzione che cancella PERMANENTEMENTE le automobili vendute prima dell'annata data in input dall'utente

parametri formali:
automobile tabella[], int &N

valore restituito:
null
*/
void cancellaAutomobiliAnnoVenditaMinore(automobile tabella[], int &N);

/*funzione che chiede all'utente la conferma per uscire dal programma

parametri formali:
bool uscita

valore restituito:
bool uscita
*/
bool uscitaProgramma(bool uscita);

#endif