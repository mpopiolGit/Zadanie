program: main.o screen.o point.o
	g++ -o program main.o screen.o point.o
	
main.o: main.cpp main.hpp
	g++ -o main.o -c main.cpp
	
screen.o: screen.cpp screen.hpp
	g++ -o screen.o -c screen.cpp
	
point.o: point.cpp point.hpp
	g++ -o point.o -c point.cpp

clean:
	rm *.o
