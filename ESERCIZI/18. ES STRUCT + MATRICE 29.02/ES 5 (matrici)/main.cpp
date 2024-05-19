/*N alunni di una classe hanno effettuato M esami. Il coordinatore della classe raccoglie
tutti i voti in una matrice N x M. Si vuole creare una procedura che presenti un menu' di
scelta che abbia le seguenti opzioni:

1. Inserimento matrice dei voti
2. Stampa della matrice
3. Stampa delle medie di tutte le materie
4. Stampa delle medie di tutti gli studenti
5. Stampa della media di un singolo studente
6. Stampa della media di una singola materia
7. Esci
*/

/**/
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // costante di partenza

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiNM(int &numero, string text);
int leggiMenu();
/*1*/ void inserimentoMatrici(int N, int M, int alunniVoti[][MAX]);
/*2*/ void stampaMatrice(int N, int M, int alunniVoti[][MAX]);
/*3*/ void stampaMedieMaterie(int N, int M, int alunniVoti[][MAX], float medieMaterie[MAX]);
/*4*/ void stampaMedieStudenti(int N, int M, int alunniVoti[][MAX], float medieStudenti[MAX]);
/*5*/ void mediaSingoloStudente(int N, int M, float medieStudenti[MAX], int alunniVoti[][MAX]);
/*6*/ void mediaSingolaMateria(int N, int M, float medieMaterie[MAX], int alunniVoti[][MAX]);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int N;                    // numero di studenti
    int M;                    // numero di materie
    int menu;                 // menu di input
    int alunniVoti[MAX][MAX]; // matrice che contiene il numero di studenti, e il numero di esami
    float medieStudenti[MAX]; // array di supporto che tiene conto delle medie degli studenti
    float medieMaterie[MAX];  // array di supporto che tiene conto delle medie delle materie
    bool flag;                // cambia se viene effettuato il primo punto

    // funzioni che permette di inserire N (numero di alunni) ed M (numero di esami)
    leggiNM(N, "\nInserisci il numero degli studenti: ");
    leggiNM(M, "\nInserisci quanti esami la classe ha sostenuto: ");

    // inizializzazione variabili
    flag = false;
    medieStudenti[0] = -1; // utile nel caso si salta il passaggio 4
    medieMaterie[0] = -1;  // utile nel caso si salta il passaggio 3

    // menù di scelta che contiene varie funzioni
    do
    {
        menu = leggiMenu();

        switch (menu)
        {
        // funzione che fa inserire per ogni studente i voti degli esami nella matrice
        case 1:
            inserimentoMatrici(N, M, alunniVoti);
            flag = true;
            break;

        // funzione che stampa i voti degli esami di ogni studente della matrice
        case 2:
            if (flag == true)
            {
                stampaMatrice(N, M, alunniVoti);
            }
            else
            {
                cout << "\nnon hai inserito nulla nella matrice!" << endl;
            }
            break;

        // funzione che calcola e stampa la media totale di ogni materia
        case 3:
            if (flag == true)
            {
                stampaMedieMaterie(N, M, alunniVoti, medieMaterie);
            }
            else
            {
                cout << "\nnon hai inserito nulla nella matrice!" << endl;
            }
            break;

        // funzione che calcola e stampa la media totale di ogni studente
        case 4:
            if (flag == true)
            {
                stampaMedieStudenti(N, M, alunniVoti, medieStudenti);
            }
            else
            {
                cout << "\nnon hai inserito nulla nella matrice!" << endl;
            }
            break;

        // funzione che stampa la media di uno studente a scelta
        case 5:
            if (flag == true)
            {
                mediaSingoloStudente(N, M, medieStudenti, alunniVoti);
            }
            else
            {
                cout << "\nnon hai inserito nulla nella matrice!" << endl;
            }
            break;

        // funzione che stampa la media di una materia a scelta
        case 6:
            if (flag == true)
            {
                mediaSingolaMateria(N, M, medieMaterie, alunniVoti);
            }
            else
            {
                cout << "\nnon hai inserito nulla nella matrice!" << endl;
            }
            break;

        // per uscire dal programma
        case 7:
            break;

        default:
            cout << "\ninserisci un'opzione valida!\n";
        }

    } while (menu != 7);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che permette di inserire N (numero di alunni) ed M (numero di esami fatti)

parametri formali:
int &N, int &M, string text

valore restituito:
null
*/
void leggiNM(int &numero, string text)
{
    do
    {
        cout << text;
        cin >> numero;
    } while (numero <= 0);
}

/*funzione che apre il menu di scelta

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu()
{
    // dichiarazione variabile
    int scelta;

    // schermata menu
    cout << "\n---------------------------------------------------------" << endl;
    cout << "1. Inserimento matrice dei voti" << endl;
    cout << "2. Stampa della matrice" << endl;
    cout << "3. Stampa delle medie di tutte le materie" << endl;
    cout << "4. Stampa delle medie di tutti gli studenti" << endl;
    cout << "5. Stampa della media di un singolo studente" << endl;
    cout << "6. Stampa della media di una singola materia" << endl;
    cout << "7. Esci\n\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*1. funzione che fa inserire per ogni studente i voti degli esami nella matrice alunniVoti [] [MAX]

parametri formali:
int N, int M, int alunniVoti [] [MAX]

valore restituito:
null
*/
void inserimentoMatrici(int N, int M, int alunniVoti[][MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    // ciclo che permette di inserire per ogni studente la valutazione di ogni esame
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cout << "\ninserisci la votazione del " << i + 1 << " studente del " << j + 1 << " esame: ";
            cin >> alunniVoti[i][j];
        }
    }
}

/*2. funzione che stampa i voti degli esami di ogni studente presi dalla matrice alunniVoti[] [MAX]

parametri formali:
int N, int M, int alunniVoti [] [MAX]

valore restituito:
null
*/
void stampaMatrice(int N, int M, int alunniVoti[][MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    // cicli che stampa i voti degli esami in colonna di ogni studente
    for (i = 0; i < N; i++)
    {
        cout << "\nstampa dei voti del " << i + 1 << " studente: \n";

        for (j = 0; j < M; j++)
        {
            cout << alunniVoti[i][j] << "   ";
        }
        cout << endl;
    }
}

/*3. funzione che calcola e stampa le medie di ogni materia, inserimento delle medie in un array di supporto

parametri formali:
int N, int M, int alunniVoti [] [MAX], float medieMaterie[MAX]

valore restituito:
null
*/
void stampaMedieMaterie(int N, int M, int alunniVoti[][MAX], float medieMaterie[MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    for (i = 0; i < M; i++)
    {
        medieMaterie[i] = 0.0;

        for (j = 0; j < N; j++)
        {
            medieMaterie[i] += alunniVoti[j][i];
        }
        medieMaterie[i] /= M;
        cout << "\nla media totale della " << i + 1 << " materia di esame e: " << medieMaterie[i] << endl;
    }
}

/*4. funzione che calcola e stampa le media totale di ogni studente, inserimento delle medie in un array di supporto

parametri formali:
int N, int medie[MAX]

valore restituito:
null
*/
void stampaMedieStudenti(int N, int M, int alunniVoti[][MAX], float medieStudenti[MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    // cicli che fano la media dei voti si ogni studente memorizzano le medie dei voti degli studenti
    for (i = 0; i < N; i++)
    {
        medieStudenti[i] = 0.0;

        for (j = 0; j < M; j++)
        {
            medieStudenti[i] += alunniVoti[i][j];
        }
        medieStudenti[i] /= M;

        // stampa delle medie di ogni studente
        cout << "\nla media totale del " << i + 1 << " studente e: " << medieStudenti[i] << endl;
    }
}

/*5. funzione che stampa la media di uno studente a scelta, riprendiamo le medie degli studenti dall'array di supporto

parametri formali:
int N, int M, float medie[MAX], int alunniVoti[][MAX]

valore restituito:
null
*/
void mediaSingoloStudente(int N, int M, float medieStudenti[MAX], int alunniVoti[][MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    // se non è ancora stata fatta la media nel passaggio 4 la si fa ora
    if (medieStudenti[0] < 0)
    {
        for (i = 0; i < N; i++)
        {
            medieStudenti[i] = 0.0;

            for (j = 0; j < M; j++)
            {
                medieStudenti[i] += alunniVoti[i][j];
            }
            medieStudenti[i] /= M;
        }
    }

    // richiesta di quale studente scegliere
    do
    {
        cout << "di quale studente vuoi controllare la media?: ";
        cin >> i;
    } while (i > N);

    cout << "\nla media del " << i << " studente e: " << medieStudenti[i - 1] << endl;
}

/*6. funzione che stampa la media di una materia a scelta

parametri formali:
int N, int M, int alunniVoti[][MAX]

valore restituito:
null
*/
void mediaSingolaMateria(int N, int M, float medieMaterie[MAX], int alunniVoti[][MAX])
{
    // dichiarazione variabili
    int i;
    int j;

    // se non è ancora stata fatta la media nel passaggio 3 la si fa ora
    if (medieMaterie[0] < 0)
    {
        for (i = 0; i < M; i++)
        {
            medieMaterie[i] = 0.0;
            for (j = 0; j < N; j++)
            {
                medieMaterie[i] += alunniVoti[j][i];
            }
            medieMaterie[i] /= M;
        }
    }

    // richiesta di quale materia scegliere
    do
    {
        cout << "di quale materia vuoi controllare la media?: ";
        cin >> i;
    } while (i > M);

    cout << "\nla media dell'esame che hai scelto (" << i << ") e: " << medieMaterie[i - 1] << endl;
}
