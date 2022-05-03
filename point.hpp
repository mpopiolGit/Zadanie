#ifndef point_hpp
#define point_hpp

class Point
{
	public:

		Point();
		void setState(bool st);		// ustawienie stanu punktu
		bool getState();			// odczyt stanu punktu

	private:

		bool state;					// stan punktu (true - polaczony, false - wolny)
};

#endif