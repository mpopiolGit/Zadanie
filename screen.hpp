#ifndef screen_hpp
#define screen_hpp

#include "point.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Screen
{
	public:

		Screen();
		~Screen();
		unsigned int countCodes(char start, unsigned char length_);			// funkcja zwracajaca liczbe mozliwych kodow

	private:

		Point points[3][3];													// tablica dwuwymiarowa punktow
		unsigned char length;												// ilosc punktow w kodzie
		unsigned int n;														// licznik pomocniczy (do wyswietlania kolejnych kodow)
		vector <char> code;													// wektor zawierajacy znaki kolejnych punktow w kodzie

		bool linkPoints(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2); // funkcja laczaca dwa punkty
		void resetCode();													// resetowanie punktow do wartosci poczatkowych
		unsigned int counter(unsigned char startX, unsigned char startY);	// funkcja rekurencyjna sprawdzajaca wszystkie mozliwe polaczenia punktow
		char xyToChar(unsigned char x, unsigned char y);					// zamiana wspolrzednych punktu na znak tekstowy
		unsigned char charToX(char c);										// zamiana znaku tekstowego na wsp. x punktu w tablicy
		unsigned char charToY(char c);										// zamiana znaku tekstowego na wsp. y punktu w tablicy
		void printCode();													// funkcja wypisujaca uzyskany kod na ekran
};

#endif