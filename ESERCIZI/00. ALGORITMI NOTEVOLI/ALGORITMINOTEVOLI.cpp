/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER INSERIMENTO QUANTITA (N)----------------------------------------
void inserimentoN(int &N)
{

    do
    {
        cout << "\ninserisci il numero di  (max " << qualcosa << "): ";
        cin >> N;
    } while (N <= 0 || N > qualcosa);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// -------------------------------- ALGORITMO PER CARICARE UNA TABELLA CON N!! ----------------------------------------

// dichiarazione variabili
int i;

// ciclo che fa inserire informazioni di ogni prodotto
for (i = 0; i < N; i++)
{
    cout << "\n\n\n*** INSERIMENTO DATI " << i + 1 << "  ***\n";

    // CONTINUA...
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// -------------------------------- ALGORITMO PER CARICARE UNA TABELLA SENZA N!! -----------------------------------------------------------

N = 0;

// controllo che non si superi il limite massimo di  ()
if (N < MAX)
{
    cout << "\n\n*** INSERIMENTO DATI " << N + 1 << "  ***\n";

    // CONTINUA...

    N++;
}
else
{
    cout << "\nnumero - MAX superato!";
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// -------------------------------- ALGORITMO PER TRASMORMARE E CONTROLLARE LETTERE E CHAR -------------------------------------------------

do
{
    cout << "\ninserisci la CLASSE ENERGETICA della casa: ";
    cin >> tabella[i].classeEnergetica;
    tabella[i].classeEnergetica = toupper(tabella[i].classeEnergetica);
} while (tabella[i].classeEnergetica < 'A' || tabella[i].classeEnergetica > 'F');

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER VERIFICARE E CONFRONTARE CON UN ARRAY UN DATO INSERITO  EX: UNA CATEGORIA----------------------------------------
do
{
    cout << "\ninserisci  (): ";
    cin >> tabella[i].categoriaMerce;

    for (j = 0; j < CATEGORIE_MAX; j++)
    {
        if (tabella[i].categoriaMerce == categorie[j])
        {
            flag = true;
            break;
        }
    }
} while (!flag);

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER STAMPA DETTAGLIATA CON TABELLE---------------------------------------------------------

for (i = 0; i < N; i++)
{
    cout << i + 1 << "  -->  nome: " << tabella[i].nome;
    cout << "   cognome: " << tabella[i].congome;
    cout << "   N di telefono: " << tabella[i].telefono;
    cout << "   categoria: " << tabella[i].categoria << "\n\n";
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// -------------------------------- ALGORITMO PER ORDINE CRESCENTE (INVERTI < PER DECRESCENTE) ----------------------------------------
for (i = 0; i < N - 1; i++)
{
    for (j = i + 1; j < N; j++)
    {
        if (tabella[i].categoriaMerce > tabella[j].categoriaMerce)
        {
            swap(tabella[i], tabella[j]);
        }
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// ------------------------------ALGORITMO PER LAVORARE CON ARRAY PROVVISORI PER FARE QUALCOSA IN SPECIFICO----------------------------

// dichiarazione variabili
int i;
int j;
int count;
x cosa[MAX];

// inizializzazione variabili
count = 0;

// ciclo che memorizza le
for (i = 0; i < N; i++)
{
    if (tabella[i].contratto == 1)
    {
        cosa[count] = tabella[i];
        count++;
    }
}

// EX MOMENTANEO --> ciclo che ordina in ordine crescente le case in affitto DELL'ARRAY PROVVISORIO
for (i = 0; i < count - 1; i++)
{
    for (j = i + 1; j < count; j++)
    {
        if (affitto[i].classeEnergia > affitto[j].classeEnergia)
        {
            swap(affitto[i], affitto[j]);
        }
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER CANCELLARE UNA PARTE DI TABELLA--------------------------------------------------

int j;
int i = 0;

while (i < N)
{
    if (tabella[i].giornoScadenza >= SCADENZAEX)
    {
        for (j = i; j < N - 1; j++)
        {
            tabella[j] = tabella[j + 1];
        }

        N--; // decremento del
    }
    else
    {
        i++; // andiamo avanti di 1 posizione
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO N NUMERI COMPRESI TRA 2 NUMERI E IL SUO EVENTUALE SWAP SE N2 < N1 ----------------------------------------

// se il prezzo 2 è minore del primo prezzo1 (cosi riesce a comprendere anche in questo caso i costi)
if (prezzo2 < prezzo1)
{
    swap(prezzo2, prezzo1);
}

// ciclo di stampa delle case che hanno un prezzo compreso tra i 2 prezzi dati in input
cout << "\n\n***STAMPA CASE COMPRESE TRA " << prezzo1 << " / " << prezzo2 << "euro***\n\n";

for (i = 0; i < N; i++)
{
    if (tabella[i].costo >= prezzo1 && tabella[i].costo <= prezzo2)
    {
        .......
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO MODIFICA UNA PARTE DI TABELLA DATA UNA STRINGA ---------------------------------------

// dichiarazione variabili
string stringa;
int i;
int j;
bool esiste; // se c'è almeno un qualcosa corrispondente alla stringa il suo valore cambia
bool flag;

// inizializzazione variabili
esiste = false;
flag = false;

// inserimento del  in input
cout << "\ninserisci il  da ricercare: ";
cin.ignore();
getline(cin, stringa);

// ciclo che controlla e modica se in alcuni contatti è presente il nome e cognome dato in input
for (i = 0; i < N; i++)
{
    // SE  CORRISPONDONO, SI PROCEDE ALLA MODIFICA DEI
    if (tabella[i].nome == stringa && tabella[i].cognome == stringa)
    {
        esiste = true;

        cout << "\n\n*** MODIFICA DATI " << i + 1 << " QUALCOSA ***\n";

        // inserimento nome NUOVO del contatto nella tabella
        cout << "\ninserisci il nome del : ";
        getline(cin, tabella[i].nome);

        // inserimento cognome NUOVO del contatto nella tabella
        cout << endl
             << "inserisci il cognome del : ";
        getline(cin, tabella[i].cognome);
    }
}

// se non c'è nessun contatto con nome e cognome corrispettivo
if (esiste == false)
{
    cout << "\nnon e stato trovato nessun !";
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER AUMENTARE LO SPAZIO DI UN ARRAY E DARE UN NUOVO VALORE----------------------------------------

// dichiarazione variabili
int i;

if (categorieEsistenti < CATEGORIE_MAX - 1)
{

    // inizializzazione variabili
    categorieEsistenti++;
    i = categorieEsistenti;

    // inserimento nuova categoria
    categorie[i] = i + 1;

    cout << "\n\n***QUALCOSA " << categorieEsistenti + 1 << " INSERITO***\n";
}
else
{
    cout << "\n\n***hai superato il massimo delle !***\n";
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// --------------------------------ALGORITMO PER DIMINUIRE LO SPAZIO DI UN ARRAY E CANCELLARE UN VALORE----------------------------------------
void cancellaCategoria()
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
