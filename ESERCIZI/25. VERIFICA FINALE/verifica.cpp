#include <iostream>
#include <string>

#include "verifica.h"

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

    // schermata menu con varie opzioni
    cout << "\n\n\n--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. Inserimento di N autovetture" << endl;
    cout << "2. Stampa del numero di tutte le auto gestite dal concessionario (quelle in vendita e quelle vendute)" << endl;
    cout << "3. Stampa di tutte le auto presenti nel concessionario (non vendute)" << endl;
    cout << "4. Stampa di tutte le auto vendute ordinate per marca (ordine alfabetico cresecente)" << endl;
    cout << "5. Stampa di tutte le auto presenti nel concessionario (non vendute) che hanno una cilindrata maggiore di un valore chiesto in input" << endl;
    cout << "6. Cancellazione di tutte le auto vendute prima dell anno inserito in input" << endl;
    cout << "7. Uscita" << endl;
    cout << "\n\n";

    // inserimento scelta/opzione input utente
    cout << "scegli l'opzione che vuoi compiere: ";
    cin >> scelta;
    cout << "\n\n";

    return scelta;
}

/*funzione che permette inserimento di un'automobile

parametri formali:
automobile tabella[], int &N

valore restituito:
null
*/
void inserimentoAutomobili(automobile tabella[], int &N)
{

    // controllo che non si superi il limite massimo di AUTOMOBILI (MAX_AUTOMOBILI)
    if (N < MAX_AUTOMOBILI)
    {
        cout << "\n\n*** INSERIMENTO DATI " << N + 1 << " AUTOMOBILE ***\n";

        // inserimento marca dell'automobile
        cout << "\ninserisci la MARCA: ";
        cin.ignore();
        getline(cin, tabella[N].marca);

        // inserimento cilindrata dell'automobile con controllo che la cilindrata non sia < di 500
        do
        {
            cout << "\ninserisci la CILINDRATA: ";
            cin >> tabella[N].cilindrata;
        } while (tabella[N].cilindrata < 500);

        // inserimento anno di immatricolazione dell'automobile con controllo che l'anno sia "valido"
        do
        {
            cout << "\ninserisci l'anno di IMMATRICOLAZIONE dell'auto: ";
            cin >> tabella[N].annoImmatricolazione;
        } while (tabella[N].annoImmatricolazione < 2000 || tabella[N].annoImmatricolazione > 2024);

        // inserimento informazione se l'auto è ancora venduta oppure presente ancora nella concessionaria
        do
        {
            cout << "\n\nautomobile e VENDUTA 0   automobile NON E VENDUTA 1\ninserisci opzione: ";
            cin >> tabella[N].isVenduta;
        } while (tabella[N].isVenduta < 0 || tabella[N].isVenduta > 1);

        // se l'automobile è stata venduta, si procede con inserimento dell'anno di vendita e dei dati dell'acquirente (nome + cognome)
        if (tabella[N].isVenduta == 0)
        {

            // inserimento dell'anno di vendita dell'automobile con controllo se l'annata è valida e non è < dell'anno di imm.
            do
            {
                cout << "\ninserisci l'anno di VENDITA: ";
                cin >> tabella[N].annoVendita;
            } while (tabella[N].annoVendita < 2000 || tabella[N].annoVendita > 2024 || tabella[N].annoVendita < tabella[N].annoImmatricolazione);

            // inserimento del nome dell'acquirente
            cout << "\ninserisci il NOME dell'acquirente: ";
            cin.ignore();
            getline(cin, tabella[N].cliente.nome);

            // inserimento del cognome dell'acquirente
            cout << "\ninserisci il COGNOME dell'acquirente: ";
            getline(cin, tabella[N].cliente.cognome);
        }

        // incremento delle AUTOMOBILI totali registrate
        N++;
    }
    else
    {
        cout << "\nnumero AUTOMOBILI max superato! (" << MAX_AUTOMOBILI << ")";
    }
}

/*funzione che stampa sia le auto non vendute, che quelle già vendute (tutte le loro informazioni)

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobili(automobile tabella[], int N)
{

    // dichiarazione variabili
    int i;

    cout << "\n\n***STAMPA DELLE AUTOMOBILI***\n\n";

    // ciclo di stampa di tutte le automobili e delle loro informazioni
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << " AUTOMOBILE  -->  marca: " << tabella[i].marca;
        cout << "   cilindrata: " << tabella[i].cilindrata;
        cout << "   anno di imm.: " << tabella[i].annoImmatricolazione;

        // controllo se la macchina è stata venduta o meno, in caso stampa di informazioni aggiuntive
        if (tabella[i].isVenduta == 0)
        {
            cout << "   stato: VENDUTA";
            cout << "   anno vendita: " << tabella[i].annoVendita;
            cout << "   nome cliente: " << tabella[i].cliente.nome;
            cout << "   cognome cliente: " << tabella[i].cliente.cognome << "\n\n";
        }
        else
        {
            cout << "   stato: NON VENDUTA\n\n";
        }
    }
}

/*funzione che stampa le automobili non vendute e le loro informazioni

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliNoVendute(automobile tabella[], int N)
{
    // dichiarazione variabili
    int i;

    cout << "\n\n***STAMPA AUTOMOBILI NON VENDUTE***\n\n";

    // ciclo di stampa delle automobili NON VENDUTE e delle loro informazioni
    for (i = 0; i < N; i++)
    {
        if (tabella[i].isVenduta == 1)
        {
            cout << i + 1 << " AUTOMOBILE  -->  marca: " << tabella[i].marca;
            cout << "   cilindrata: " << tabella[i].cilindrata;
            cout << "   anno di imm.: " << tabella[i].annoImmatricolazione;
            cout << "   stato: NON VENDUTA\n\n";
        }
    }
}

/*funzione che stampa e ordina crescentemente le automobili vendute e le loro informazioni

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliVendutaMarca(automobile tabella[], int N)
{
    // dichiarazione variabili
    int i;
    int j;
    int count;                          // va ad indicare la posizione di memorizzazione della tabella di supporto
    automobile vendute[MAX_AUTOMOBILI]; // tabella di supporto dove andiamo a memorizzare le automobili VENDUTE

    // inizializzazione variabili
    count = 0;

    // ciclo che memorizza le automobili vendute all'interno della tabella di supporto
    for (i = 0; i < N; i++)
    {
        if (tabella[i].isVenduta == 0)
        {
            vendute[count] = tabella[i];
            count++;
        }
    }

    // cicli che ordinano in ordine crescente x MARCA le automobili vendute, presenti nella tabella provvisoria
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (vendute[i].marca > vendute[j].marca)
            {
                swap(vendute[i], vendute[j]);
            }
        }
    }

    cout << "\n\n***STAMPA AUTOMOBILI VENDUTE ORDINATE X MARCA ***\n\n";

    // ciclo di stampa delle automobili vendute ordinate, presenti nella tabella di supporto
    for (i = 0; i < count; i++)
    {
        cout << i + 1 << " AUTOMOBILE VENDUTA  -->  marca: " << vendute[i].marca;
        cout << "   cilindrata: " << vendute[i].cilindrata;
        cout << "   anno di imm.: " << vendute[i].annoImmatricolazione;
        cout << "   stato: VENDUTA";
        cout << "   anno vendita: " << vendute[i].annoVendita;
        cout << "   nome cliente: " << vendute[i].cliente.nome;
        cout << "   cognome cliente: " << vendute[i].cliente.cognome << "\n\n";
    }
}

/*funzione che stampa le automobili (sia vendute che non) che hanno una cilindrata > di una data in input dall'utente

parametri formali:
automobile tabella[], int N

valore restituito:
null
*/
void stampaAutomobiliCilindrataAlta(automobile tabella[], int N)
{
    // dichiarazione variabili
    int i;
    int inputCilindrata; // cilindrata data in input dall'utente

    // inserimento della cilindrata dell'utente con controllo di validità sulla cilindrata (no negativo)
    do
    {
        cout << "\ninserisci la CILINDRATA da te desiderata: ";
        cin >> inputCilindrata;
    } while (inputCilindrata < 0);

    cout << "\n\n***STAMPA AUTOMOBILI CON CILINDRATA > DI " << inputCilindrata << "***\n\n";

    // ciclo per trovare le automobili con una cilindrata > di quella data in input
    for (i = 0; i < N; i++)
    {
        // se la cilindrata dell'automobile è > di quella data in input stampa le sue informazioni
        if (tabella[i].cilindrata > inputCilindrata)
        {
            cout << i + 1 << " AUTOMOBILE  -->  marca: " << tabella[i].marca;
            cout << "   cilindrata: " << tabella[i].cilindrata;
            cout << "   anno di imm.: " << tabella[i].annoImmatricolazione;

            // controllo se la macchina è stata venduta o meno, in caso aggiunta di informazioni relative alla vendita
            if (tabella[i].isVenduta == 0)
            {
                cout << "   stato: VENDUTA";
                cout << "   anno vendita: " << tabella[i].annoVendita;
                cout << "   nome cliente: " << tabella[i].cliente.nome;
                cout << "   cognome cliente: " << tabella[i].cliente.cognome << "\n\n";
            }
            else
            {
                cout << "   stato: NON VENDUTA\n\n";
            }
        }
    }
}

/*funzione che cancella PERMANENTEMENTE le automobili vendute prima dell'annata data in input dall'utente

parametri formali:
automobile tabella[], int &N

valore restituito:
null
*/
void cancellaAutomobiliAnnoVenditaMinore(automobile tabella[], int &N)
{
    // dichiarazione variabili
    int i;
    int j;
    int inputAnnata; // annata data in input dall'utente

    // inizializzazione variabile
    i = 0;

    // inserimento dell'annata data dall'utente con controllo di validità
    do
    {
        cout << "\ninserisci l'ANNATA da te desiderata: ";
        cin >> inputAnnata;
    } while (inputAnnata < 2000 || inputAnnata > 2024);

    cout << "\n\n***CANCELLAZIONE AUTOMOBILI CON ANNO VENDITA < DI " << inputAnnata << "***\n\n";

    // algoritmo per cancellare le automobili che hanno un'anno di vendita < di quella data in input dall'utente
    while (i < N)
    {
        if (tabella[i].isVenduta == 0 && tabella[i].annoVendita < inputAnnata)
        {
            for (j = i; j < N - 1; j++)
            {
                tabella[j] = tabella[j + 1];
            }

            N--; // decremento del numero totale di automobili
        }
        else
        {
            i++; // andiamo avanti di 1 posizione nella tabella
        }
    }
}

/*funzione che chiede all'utente la conferma per uscire dal programma

parametri formali:
bool uscita

valore restituito:
bool uscita
*/
bool uscitaProgramma(bool uscita)
{

    // dichiarazione variabili
    int inputUscita;

    // ciclo con verifica dell'input che chiede se uscire o rimanere nel programma + controllo
    do
    {
        cout << "\nUSCITA PROGRAMMA 1      RIMANI 0\ninserisci opzione: ";
        cin >> inputUscita;

        if (inputUscita == 1)
        {
            uscita = true;
        }

    } while (inputUscita < 0 || inputUscita > 1);

    return uscita;
}