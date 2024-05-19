#ifndef _CASE_
#define _CASE_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N_MAX_CASE 10  // numero massimo di case inseribili
#define energetica 6   // capienza massima array con le classi energetiche
#define prezzoMIN 1000 // prezzo minimo della casa
#define prezzoMAX 3000 // prezzo massimo della casa

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con informazioni e dati relativi alla casa
struct casa
{
    int superficie;     // in mq
    char classeEnergia; // classe energetica della casa (A-F)
    float costo;        // costo della casa
    int contratto;      // tipo di contratto della casa (vendita/affitto)
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
void inserimentoCasa(casa tabella[], int &N, char classeEnergetiche[]);
void stampaCase(casa tabella[], int N);
void stampaCaseAffitto(casa tabella[], int N);
void stampaCasePrezzo(casa tabella[], int N);

#endif