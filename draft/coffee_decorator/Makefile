coffee: main.o PlainCoffee.o CoffeeDecorator.o MilkDecorator.o SugarDecorator.o
	g++ -o coffee main.o PlainCoffee.o CoffeeDecorator.o MilkDecorator.o SugarDecorator.o -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
PlainCoffee.o: PlainCoffee.cpp PlainCoffee.h Coffee.h
	g++ -c PlainCoffee.cpp -Wall
CoffeeDecorator.o: CoffeeDecorator.cpp CoffeeDecorator.h Coffee.h
	g++ -c CoffeeDecorator.cpp -Wall
MilkDecorator.o: MilkDecorator.cpp MilkDecorator.h CoffeeDecorator.h
	g++ -c MilkDecorator.cpp -Wall
SugarDecorator.o: SugarDecorator.cpp SugarDecorator.h CoffeeDecorator.h
	g++ -c SugarDecorator.cpp -Wall
clean:
	rm -rf *.o coffee
