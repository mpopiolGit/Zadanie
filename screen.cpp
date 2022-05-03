#include "screen.hpp"

Screen::Screen() {
	length = 0;
	n = 0;
}

Screen::~Screen(){
	code.clear();
}

char Screen::xyToChar(unsigned char x, unsigned char y) {
	return (y * 3 + x + 65);
}

unsigned char Screen::charToX(char c) {
	return (c - 65) % 3;
}

unsigned char Screen::charToY(char c) {
	return (c - 65) / 3;
}

bool Screen::linkPoints(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {

	char dx = x2 - x1;										// zmienne okreslajace kierunek i dlugosc polaczenia miedzy punktami
	char dy = y2 - y1;

	if (!points[x2][y2].getState()) {						// sprawdz czy punkt docelowy byl juz uzyty
		if ((abs(dx) < 2 && abs(dy) < 2) || (abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) { // polaczenia 'krotkie' (pion, poziom, ukos) lub 'dlugie' diagonalne bez przeciec
			points[x2][y2].setState(true);					// ustaw stan punktu docelowego jako u¿yty
			points[x1][y1].setState(true);					// ustaw stan punktu startowego jako u¿yty
			code.push_back(xyToChar(x2, y2));
			return true;
		}
		else	// polaczenie dlugie (pion, poziom, diagonalne) - mozliwe tylko, jesli punkt przecinany jest juz polaczony
		{
			if (abs(dx) == 2 && abs(dy) == 0 && points[1][y2].getState()) { // poziom
				points[x2][y2].setState(true); 
				points[x1][y1].setState(true);
				code.push_back(xyToChar(x2, y2));
				return true;

			}
			else if (abs(dx) == 0 && abs(dy) == 2 && points[x2][1].getState()) { // pion
				points[x2][y2].setState(true); 
				points[x1][y1].setState(true);
				code.push_back(xyToChar(x2, y2));
				return true;
			}
			else if (points[1][1].getState()) { // diagonalne
				points[x2][y2].setState(true); 
				points[x1][y1].setState(true);
				code.push_back(xyToChar(x2, y2));
				return true;
			}
			else {
				return false; 
			} 
			return false; 
		}

	}
	else { 
		return false;
	}
}

void Screen::printCode() {
	cout << "\t" << n << ".\t" << code[0];
	if (code.size() > 0) {
		for (unsigned char i = 1; i < code.size(); i++) {
			cout << " -> " << code[i];
		}
	}
	cout << "\n";
}

void Screen::resetCode() {
	n = 0;
	code.clear();
	for (unsigned char i = 0; i < 3; i++) {
		for (unsigned char j = 0; j < 3; j++) {
			points[i][j].setState(false);
		}
	}
}

unsigned int Screen::countCodes(char start, unsigned char length_) {

	resetCode();
	length = length_;

	code.push_back(start);
	points[charToX(start)][charToY(start)].setState(true);

	return counter(charToX(start), charToY(start));
}

unsigned int Screen::counter(unsigned char startX, unsigned char startY) {
	unsigned int count = 0;
	length--;

	if (length > 0)
	{
		for (unsigned char i = 0; i < 3; i++) {
			for (unsigned char j = 0; j < 3; j++) {
				if (linkPoints(startX, startY, j, i)) {
					count += counter(j, i);
				}
			}
		}
		points[startX][startY].setState(false);
		length++; 
		code.pop_back();
		return count;
	}
	else
	{
		length++;
		n++;
		points[startX][startY].setState(false);
		printCode();
		code.pop_back();
		return ++count;
	}
}