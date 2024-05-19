/*Si confronta la chiave K con l’elemento che si trova a metà vettore. Se l’elemento individuato non è uguale a
quello cercato si prosegue la ricerca nel semivettore inferiore o superiore a seconda che la chiave
sia più piccola o più grande dell’elemento che si trova a metà.

● La ricerca termina con successo quando si trova la chiave

● La ricerca termina con insuccesso quando la parte del vettore considerato
è costituita da un solo elemento*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
const int MAX = 15;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/
void generazioneK(int &K);
void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void confrontiChiave(int numeri[], int N, int K);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int numeri[MAX];
    int K;
    int N;

    // inizializzazione del seme
    srand(time(NULL));

    // funzione che genera la chiave (K) casualmente
    generazioneK(K);

    // funzione che legge la dimensione dell'array
    leggiN(N, MAX);

    // funzione che legge i numeri dell'array
    leggiNumeri(numeri, N);

    // funzione che cicla ogni elemento e contolla se = K
    confrontiChiave(numeri, N, K);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che genera la chiave K causalmente

parametri formali:
null


valore restituito:
int &K
*/
void generazioneK(int &K)
{
    // generazione di un numero tra 1 e 10
    K = rand() % 10 + 1;
    cout << "la chiave K e: " << K << endl;
}

/*funzione che legge il numero N (1-15) inserito dall'user

parametri formali:
int &, const int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX)
{
    do
    {
        cout << "\ninserisci quanti numeri vuoi registrare nell'array (1-15): ";
        cin >> N;
    } while (N < 1 || N > MAX);
}

/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void leggiNumeri(int numeri[], int N)
{
    // dichiarazione variabili
    int i;

    // ciclo per memorizzare i numeri inseriti dall'user
    for (i = 0; i < N; i++)
    {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}

/*funzione che ricerca un elemento = K partendo dall'elemento in mezzo

parametri formali:
int numeri[], int N, int K

valore restituito:
null
*/
void confrontiChiave(int numeri[], int N, int K)
{
    // dichiarazione variabili
    int t;
    int u;
    int i;

    // inizializzazione delle variabili
    t = 0;
    u = N;

    do
    {
        // inizializzazione della posizione del vettore
        i = (t + u) / 2;

        if (K != numeri[i])
        {
            if (K > numeri[i])
            {
                t = i++;
            }
            else
            {
                u = i--;
            }
        }

    } while (t <= u && K != numeri[i]);

    // stampa se l'elemento dell'array che ha scalato è = a K oppure no
    if (K != numeri[i])
    {
        cout << "\n\nelemento NON trovato!";
    }
    else
    {
        cout << "\n\nelemento trovato!";
    }
}
