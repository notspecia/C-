/*Si vuole costruire un programma che gestisca i voti di una materia di una classe di
studenti. I voti durante l’anno possono essere al massimo 10, ma non tutti gli studenti
hanno lo stesso numero di voti.
I dati di cui si dispone sono: nome studente e successione di voti (max 10).
Scrivere la procedura di input dei dati.
Stampare in output i nomi degli studenti e la loro media, ordinati per media decrescente.*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// variabili globali
const int STUDENTI_MAX = 20;
const int VOTI_MAX = 10;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struct informazioni relative agli studenti
struct studenti
{
    string nome;        // nome dello studente
    int Nvoti;          // numero dei voti dello studente
    int voti[VOTI_MAX]; // array che contiene i voti dello studente
    float media;        // media dei voti dello studente
};

/*							FUNCTION SIGNATURE
------------------------------------------------------- -------------*/

void inserimentoN(int &N);
void caricaTabella(studenti tabella[], int N);
void calcoloMedia(studenti tabella[], int N);
void stampaMedie(studenti tabella[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                          // numero di studenti nella classe
    studenti tabella[STUDENTI_MAX]; // tabella che memorizza informazioni degli studenti

    // funzione che permette inserimento N studenti (max 20)
    inserimentoN(N);

    // funzione che memorizza le informazioni di ogni studente nella tabella
    caricaTabella(tabella, N);

    // funzione che calcola la media degli studenti
    calcoloMedia(tabella, N);

    // funzione che stampa le medie degli studenti in ordine DECRESCENTE
    stampaMedie(tabella, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che permette inserimento N studenti (max 20)

parametri formali:
int &N

valore restituito:
null
*/
void inserimentoN(int &N)
{

    do
    {
        cout << "inserisci il numero di studenti della classe max (" << STUDENTI_MAX << "): ";
        cin >> N;
    } while (N <= 0 || N > STUDENTI_MAX);
}

/*funzione che memorizza le informazioni di ogni studente nella tabella

parametri formali:
studenti tabella[STUDENTI_MAX], int N

valore restituito:
null
*/
void caricaTabella(studenti tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // ciclo che inserisce informazioni degli studenti
    for (i = 0; i < N; i++)
    {
        cout << "\n\n*** INSERIMENTO DATI DEL " << i + 1 << " STUDENTE ***\n";

        // nome dello studente
        cout << "inserisci il nome dello studente: ";
        cin.ignore();
        getline(cin, tabella[i].nome);

        // numero di voti
        do
        {
            cout << "quanti voti ha lo studente (0-10): ";
            cin >> tabella[i].Nvoti;
        } while (tabella[i].Nvoti <= 0 || tabella[i].Nvoti > VOTI_MAX);

        // inserimento dei voti dello studente
        for (j = 0; j < tabella[i].Nvoti; j++)
        {
            cout << "inserisci il " << j + 1 << " voto: ";
            cin >> tabella[i].voti[j];
        }
    }
}

/*funzione che calcola la media degli studenti

parametri formali:
studenti tabella[STUDENTI_MAX], int N

valore restituito:
null
*/
void calcoloMedia(studenti tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // cicli che fanno la media dei voti di ogni studente
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < tabella[i].Nvoti; j++)
        {
            tabella[i].media += tabella[i].voti[j];
        }
        tabella[i].media /= tabella[i].Nvoti;
    }
}

/*funzione che ordina e stampa le medie degli studenti in ordine DECRESCENTE

parametri formali:
studenti tabella[STUDENTI_MAX], int N

valore restituito:
null
*/
void stampaMedie(studenti tabella[], int N)
{

    // dichiarazione variabili
    int i;
    int j;

    // cicli che mette in ordine DECRESCENTE le medie
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (tabella[j].media < tabella[j + 1].media)
            {
                swap(tabella[j], tabella[j + 1]);
            }
        }
    }

    // ciclo che stampa le medie
    cout << "\n\n\n*** MEDIE DEGLI STUDENTI ***\n";
    for (i = 0; i < N; i++)
    {
        cout << "\nal " << i + 1 << " posto, abbiamo lo studente di nome: " << tabella[i].nome << ", con la media di: " << tabella[i].media << endl;
    }
}
