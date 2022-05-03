#include "main.hpp"

int main ()
{
	char start = 0;
	unsigned int length = 0;
	unsigned int result = 0;
	Screen scr;

	cout << "\n\tWpisanie znaku Q jako znaku startowego zakonczy dzialanie programu\n\n";

	while (1)
	{
		result = 0;

		cout << "\n\tPodaj znak startowy: ";
		cin >> start;

		if (start == 'Q')
			return 0;

		if (64 < start && start < 75) {

			cout << "\n\tPodaj ilosc punktow skladajacych sie na kod: ";
			cin >> length;

			if (length > 1 && length < 10) {
				cout << "\n\tMozliwe do uzyskania kody:\n\n";
				result = scr.countCodes(start, length);
				cout << "\n\tLiczba wszystkich mozliwych kodow: " << result << "\n";
			}
			else {
				cout << "\n\tIlosc punktow moze byc liczba z zakresu od 2 do 9\n";
			}

		}
		else {
			cout << "\n\tWprowadzono znak spoza zakresu (A B C D E F G H I)\n";
		}
		cout << "\n\t****************************************************\n";
	}

	return 0;
}
