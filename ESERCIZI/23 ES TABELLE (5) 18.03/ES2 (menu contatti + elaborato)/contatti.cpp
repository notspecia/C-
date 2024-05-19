#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "contatti.h"
using namespace std;

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che apre il menu di scelta all'utente

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu()
{

    // dichiarazione variabili
    int scelta;

    // schermata menu
    cout << "\n\n\n--------------------------------------------------------------------------------------------" << endl;
    cout << "1. Inserimento di N contatti" << endl;
    cout << "2. Stampa dei contatti presenti" << endl;
    cout << "3. Eliminazione dei contatti appartenenti a una categoria (data in input)" << endl;
    cout << "4. Stampa ordinata alfabeticamente per cognome dei contatti appartenenti a una categoria (data in input)" << endl;
    cout << "5. Modifica di un contatto dato il nome e cognome" << endl;
    cout << "6. Cancellazione di un contatto dato il nome e cognome" << endl;
    cout << "7. Ricerca di un contatto dato il nome e cognome" << endl;
    cout << "8. Inserimento di una categoria" << endl;
    cout << "9. Cancellazione di una categoria" << endl;
    cout << "10. Esci\n"
         << endl;

    // inserimento scelta
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette inserimento dati nela tabella dei contatti

parametri formali:
contatti tabella[], int &N, int categorie[]

valore restituito:
null
*/
void inserimentoContatti(contatti tabella[], int &N, int categorie[], int categorieEsistenti)
{

    // dichiarazione variabili
    int i;
    bool flag;

    // inizializzazione variabili
    flag = false;

    // controllo che non si superi il limite massimo di case (10)
    if (N < CONTATTI_MAX)
    {
        cout << "\n\n*** INSERIMENTO DATI " << N + 1 << " CONTATTO ***\n";

        // inserimento nome del contatto nella tabella
        cout << "\ninserisci il nome del contatto: ";
        cin.ignore();
        getline(cin, tabella[N].nome);

        // inserimento cognome del contatto nella tabella
        cout << endl
             << "inserisci il cognome del contatto: ";
        getline(cin, tabella[N].cognome);

        // inserimento RANDOMICO del numero di telefono nella tabella
        tabella[N].telefono = 3000000 + rand() % 1000000;
        cout << "\ninserisci numero di telefono del contatto: " << tabella[N].telefono;

        // inserimento della categoria nella tabella
        do
        {
            cout << "\n\ninserisci la categoria del contatto (1-" << categorieEsistenti + 1 << "): ";
            cin >> tabella[N].categoria;

            for (i = 0; i < categorieEsistenti + 1 && flag != true; i++)
            {

                if (tabella[N].categoria == categorie[i])
                {
                    flag = true;
                }
            }
        } while (!flag);

        // incremento dei contatti totali registrati
        N++;
    }
    else
    {
        cout << "\nnumero CONTATTI max superato!";
    }
}

/*funzione che stampa i contatti e le sue informazioni

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void stampaContatti(contatti tabella[], int N)
{

    // dichiarazione variabili
    int i;

    // ciclo di stampa delle case
    cout << "\n\n***STAMPA DI TUTTI I CONTATTI***\n\n";
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " CONTATTO -->  nome: " << tabella[i].nome;
        cout << "   cognome: " << tabella[i].cognome;
        cout << "   N di telefono: " << tabella[i].telefono;
        cout << "   categoria: " << tabella[i].categoria << "\n\n";
    }
}

/*funzione che elimina i contatti appartenenti ad una categoria
parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void cancellaContatti(contatti tabella[], int &N, int categorie[], int categorieEsistenti)
{

    // dichiarazione variabili
    int i;
    int j;
    int categoriaInput; // input della categoria da cancellare
    bool flag;          // il valore cambia quando viene inserita una categoria valida

    // inizializzazione variabili
    flag = false;

    // input categoria
    do
    {
        cout << "\ninserisci la categoria da ELIMINARE: ";
        cin >> categoriaInput;

        for (i = 0; i < categorieEsistenti + 1 && flag != true; i++)
        {

            if (categorie[i] == categoriaInput)
            {
                flag = true;
            }
        }

    } while (!flag);

    // ciclo con algoritmo che cancella dalla tabella i contatti appartenenti ad una categoria
    
    // re-inizializzazione iteratore
    i = 0;
    while (i < N)
    {
        if (tabella[i].categoria == categoriaInput)
        {
            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }
            N--; // decremento del numero contatti
        }
        else
        {
            i++;
        }
    }
}

/*funzione che ordina e stampa i contatti appartenenti a una categoria in ordine crescente alfabetico in base al cognome

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void ordinaContatti(contatti tabella[], int N, int categorie[], int categorieEsistenti)
{

    // dichiarazione variabili
    int i;
    int j;
    int categoriaInput;                     // input della categoria da ordinare
    int count;                              // conteggio dei contatti appartenenti a una categoria
    bool flag;                              // il valore cambia quando viene inserita una categoria valida
    contatti categoriaScelta[CONTATTI_MAX]; // array provvisorio per memorizzare le info della categoria selezionata

    // inizializzazione variabili
    count = 0;
    flag = false;

    // input categoria
    do
    {
        cout << "\ninserisci la categoria da ORDINARE: ";
        cin >> categoriaInput;

        for (i = 0; i < categorieEsistenti + 1 && flag != true; i++)
        {

            if (categorie[i] == categoriaInput)
            {
                flag = true;
            }
        }

    } while (!flag);

    // ciclo che memorizza i contatti della categoria nell'array provvisorio
    for (i = 0; i < N; i++)
    {
        if (tabella[i].categoria == categoriaInput)
        {
            categoriaScelta[count] = tabella[i];
            count++;
        }
    }

    // ciclo che fa ordinamento crescente della categoria scelta in base al cognome
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {

            if (categoriaScelta[i].cognome > categoriaScelta[j].cognome)
            {
                swap(categoriaScelta[i], categoriaScelta[j]);
            }
        }
    }

    // ciclo che stampa i contatti della categoria
    cout << "\n\n***STAMPA ORDINE CRESCENTE (cognome) CONTATTI CATEGORIA " << categoriaInput << " ***\n\n";
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << " CONTATTO -->  nome: " << categoriaScelta[i].nome;
        cout << "   cognome: " << categoriaScelta[i].cognome;
        cout << "   N di telefono: " << categoriaScelta[i].telefono;
        cout << "   categoria: " << categoriaScelta[i].categoria << "\n\n";
    }
}

/*funzione che modifica i contatti che hanno il nome e cognome corrispondente a quello inserito

parametri formali:
contatti tabella[], int N, int categorie[]

valore restituito:
null
*/
void modificaContattiConNomeCognome(contatti tabella[], int N, int categorie[], int categorieEsistenti)
{

    // dichiarazione variabili
    string inputNome;    // input del nome inserito dall'utente
    string inputCognome; // input del cognome inserito dall'utente
    int i;
    int j;
    bool esiste; // se c'è almeno un nome e cognome corrispondente il suo valore cambia
    bool flag;

    // inizializzazione variabili
    esiste = false;
    flag = false;

    // inserimento del nome in input
    cout << "\ninserisci il nome da ricercare: ";
    cin.ignore();
    getline(cin, inputNome);

    // inserimento del cognome in input
    cout << endl
         << "inserisci il cognome da ricercare: ";
    getline(cin, inputCognome);

    // ciclo che controlla e modica se in alcuni contatti è presente il nome e cognome dato in input
    for (i = 0; i < N; i++)
    {
        // SE NOME E COGNOME CORRISPONDONO, SI PROCEDE ALLA MODIFICA DEI CONTATTI
        if (tabella[i].nome == inputNome && tabella[i].cognome == inputCognome)
        {
            esiste = true;

            cout << "\n\n*** MODIFICA DATI " << i + 1 << " CONTATTO ***\n";

            // inserimento nome NUOVO del contatto nella tabella
            cout << "\ninserisci il nome del contatto: ";
            getline(cin, tabella[i].nome);

            // inserimento cognome NUOVO del contatto nella tabella
            cout << endl
                 << "inserisci il cognome del contatto: ";
            getline(cin, tabella[i].cognome);

            // inserimento RANDOMICO NUOVO del numero di telefono nella tabella
            tabella[i].telefono = 3000000 + rand() % 1000000;
            cout << "\ninserisci numero di telefono del contatto: " << tabella[i].telefono;

            // inserimento della NUOVA categoria nella tabella
            do
            {
                cout << "\n\ninserisci la categoria del contatto (1-" << categorieEsistenti + 1 << "): ";
                cin >> tabella[i].categoria;

                for (j = 0; j < categorieEsistenti + 1 && flag != true; j++)
                {

                    if (tabella[i].categoria == categorie[j])
                    {
                        flag = true;
                    }
                }
            } while (!flag);
        }
    }

    // se non c'è nessun contatto con nome e cognome corrispettivo
    if (esiste == false)
    {
        cout << "\nnon e stato trovato nessun contatto!";
    }
}

/*funzione che cancella un contatto / contatti dato il nome e cognome

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void cancellaContattiConNomeCognome(contatti tabella[], int &N)
{

    // dichiarazione variabili
    string inputNome;    // input inserito dall'utente
    string inputCognome; // input inserito dall'utente
    int i;
    int j;
    bool esiste; // se c'è almeno un nome e cognome corrispondente il suo valore cambia

    // inizializzazione variabili
    i = 0;
    esiste = false;

    // inserimento del nome in input
    cout << "\ninserisci il nome da ricercare: ";
    cin.ignore();
    getline(cin, inputNome);

    // inserimento del cognome in input
    cout << endl
         << "inserisci il cognome da ricercare: ";
    getline(cin, inputCognome);

    // ciclo che controlla e cancella i contatti in cui il nome e cognome è = a quelli dati in input

    while (i < N)
    {
        if (tabella[i].nome == inputNome && tabella[i].cognome == inputCognome)
        {
            esiste = true;

            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }
            N--; // decremento del numero contatti
        }
        else
        {
            cout << "\n\n***CONTATTO " << i << " ELIMINATO***\n";
            i++;
        }
    }

    // se non c'è nessun contatto con nome e cognome corrispettivo
    if (esiste == false)
    {
        cout << "\nnon e stato trovato nessun contatto!";
    }
}

/*funzione che ricerca un contatto dato il nome e cognome

parametri formali:
contatti tabella[], int N

valore restituito:
null
*/
void ricercaContattiConNomeCognome(contatti tabella[], int N)
{

    // dichiarazione variabili
    string inputNome;    // input inserito dall'utente
    string inputCognome; // input inserito dall'utente
    int i;
    int j;
    bool esiste; // se c'è almeno un nome e cognome corrispondente il suo valore cambia

    // inizializzazione variabili
    i = 0;
    esiste = false;

    // inserimento del nome in input
    cout << "\ninserisci il nome da ricercare: ";
    cin.ignore();
    getline(cin, inputNome);

    // inserimento del cognome in input
    cout << endl
         << "inserisci il cognome da ricercare: ";
    getline(cin, inputCognome);

    // ciclo che ricerca i contatti in cui il nome e cognome è = a quelli dati in input
    cout << "\n\n***CONTATTI TROVATI***\n";
    for (i = 0; i < N; i++)
    {

        if (tabella[i].nome == inputNome && tabella[i].cognome == inputCognome)
        {
            esiste = true;
            cout << "\ncontatto " << i + 1 << " trovato";
        }
    }

    // se non c'è nessun contatto con nome e cognome corrispettivo
    if (esiste == false)
    {
        cout << "\nnon e stato trovato nessun contatto!";
    }
}

/*funzione che crea una nuova categoria

parametri formali:
int categorie[], int &categorieEsistenti

valore restituito:
null
*/
void inserimentoCategoria(int categorie[], int &categorieEsistenti)
{
    // dichiarazione variabili
    int i;

    if (categorieEsistenti < CATEGORIE_MAX - 1)
    {

        // inizializzazione variabili
        categorieEsistenti++;
        i = categorieEsistenti;

        // inserimento nuova categoria
        categorie[i] = i + 1;

        cout << "\n\n***CATEGORIA " << categorieEsistenti + 1 << " INSERITO***\n";
    }
    else
    {
        cout << "\n\n***hai superato il massimo delle categorie!***\n";
    }
}

/*funzione che cancella una categoria

parametri formali:
int categorie[], int &categorieEsistenti

valore restituito:
null
*/
void cancellaCategoria(int categorie[], int &categorieEsistenti)
{

    // dichiarazione variabili
    int i;
    int j;

    // inizializzazione variabili
    i = 0;

    if (categorieEsistenti != 0)
    {

        cout << "\n\n***CATEGORIA " << categorieEsistenti << " ELIMINATO***\n";

        // ciclo che elimina una categoria nell'array
        while (i < categorieEsistenti)
        {
            if (categorie[i] == categorieEsistenti)
            {
                for (j = i; j < categorieEsistenti - 1; j++)
                {
                    categorie[j] = categorie[j + 1];
                }
                categorieEsistenti--; // decremento del numero di categorie
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        cout << "\n\n***non puoi cancellare + categorie!***\n";
    }
}