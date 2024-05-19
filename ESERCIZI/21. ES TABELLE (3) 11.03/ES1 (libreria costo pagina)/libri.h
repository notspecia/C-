#ifndef _LIBRI_
#define _LIBRI_

#include <iostream>
#include <string>
using namespace std;

// variabile globale
const int LIBRI_MAX = 10;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struct con informazioni sui libri
struct libri
{
    int codice;
    int numeroPagine;
    float costo;
    float costoXpagina;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoN(int &N);
void caricaTabella(libri tabella[], int N);
void prezzoPagina(libri tabella[], int N);
void stampaPagina(libri tabella[], int N);

#endif