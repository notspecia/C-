/*Si abbia in input un numero N. Stampare i dieci numeri pari successivi al numero N.*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int N; // numero da inserire
	int i; // iteratore

	cout << "inserisci un numero: ";
	cin >> N;

	cout << "i primi dieci numeri pari dopo il numero " << N << " sono:" << endl;

	if (N % 2 != 0)
	{
		N--;
	}

	for (i = 0; i < 10; i++)
	{
		N = N + 2;
		cout << N << endl;
	}
	return 0;
}