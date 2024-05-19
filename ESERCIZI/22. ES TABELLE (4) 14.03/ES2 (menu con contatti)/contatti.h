#ifndef _CONTATTI_
#define _CPNTATTI_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define CATEGORIE_MAX 5 //categorie massime 
#define CONTATTI_MAX 10 //contatti massimi
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura con informazioni sui contatti
struct contatti
{
    string nome;
    string congome;
    int telefono;
    int categoria;
};

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
void inserimentoContatti(contatti tabella[], int &N, int categorie[]);
void stampaContatti(contatti tabella[], int N);
void cancellaContatti(contatti tabella[], int &N, int categorie[]);
void ordinaContatti(contatti tabella[], int N, int categorie[]);

#endif