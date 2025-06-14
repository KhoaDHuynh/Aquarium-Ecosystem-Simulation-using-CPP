main: main.o Coffee.o
	g++ -o main main.o Coffee.o -Wall
main.o: main.cpp Coffee.h 
	g++ -c main.cpp -Wall
Coffe.o: Coffee.cpp Coffee.h 
	g++ -c Coffee.cpp -Wall
clean:
	del -f *.o main