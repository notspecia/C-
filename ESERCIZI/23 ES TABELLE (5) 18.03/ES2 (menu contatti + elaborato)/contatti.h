#ifndef _CONTATTI_
#define _CONTATTI_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define CATEGORIE_MAX 10 // categorie massime
#define CONTATTI_MAX 10  // contatti massimi

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con informazioni sui contatti
struct contatti
{
    string nome;
    string cognome;
    int telefono;
    int categoria;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

// funzione che legge il menu di scelta
int leggiMenu();

// funzione che permette inserimento di contatti
void inserimentoContatti(contatti tabella[], int &N, int categorie[], int categorieEsistenti);

// funzione che stampa tutti i contatti
void stampaContatti(contatti tabella[], int N);

// funzione che elimina i contatti appartenenti ad una categoria
void cancellaContatti(contatti tabella[], int &N, int categorie[], int categorieEsistenti);

// funzione che ordina e stampa i contatti appartenenti a una categoria in ordine crescente alfabetico in base al cognome
void ordinaContatti(contatti tabella[], int N, int categorie[], int categorieEsistenti);

// funzione che modifica un contatto dato il nome e cognome
void modificaContattiConNomeCognome(contatti tabella[], int N, int categorie[], int categorieEsistenti);

// funzione che cancella un contatto dato il nome e cognome
void cancellaContattiConNomeCognome(contatti tabella[], int &N);

// funzione che ricerca un contatto dato il nome e cognome
void ricercaContattiConNomeCognome(contatti tabella[], int N);

// funzione che inserisce una nuova categoria
void inserimentoCategoria(int categorie[], int &categorieEsistenti);

// funzione che cancella una categoria
void cancellaCategoria(int categorie[], int &categorieEsistenti);

#endif