#include <iostream>
#include <string>
using namespace std;


//COSTANTE FISSA
const int MAX = 100;




/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int chiediDimensione();
void caricaVettore(int v[], int d);
int somma(int v[], int d);






/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    int n;
    int v[MAX];
    int tot;
    n = chiediDimensione();
    cout << "Carica elementi vett \n";
    caricaVettore(v, n);
    tot = somma(v, n);
    cout << "Somma = " << tot << endl;
    return 0;
}





/*								FUNZIONI
--------------------------------------------------------------------*/

// inserimento dimensione array
int chiediDimensione()
{
    int d;

    do
    {
        cout << "Dim vett : ";
        cin >> d;
    } while (d < 1 || d > MAX);
    return d;
}



// caricamento vett
void caricaVettore(int v[], int d)
{
    int i;
    for (i = 0; i < d; i++)
    {
        cout << "Ele " << i << " : ";
        cin >> v[i];
    }
}



// Somma componenti vett
int somma(int v[], int d)
{
    int s = 0;
    int i;
    for (i = 0; i < d; i++)
        s += v[i];
    return s;
}