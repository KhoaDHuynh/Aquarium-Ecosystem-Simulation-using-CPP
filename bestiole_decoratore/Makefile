main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleDecorator.o EyesDecorator.o EarsDecorator.o Nageoires.o Carapace.o Camouflage.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleDecorator.o EyesDecorator.o EarsDecorator.o Nageoires.o Carapace.o Camouflage.o -I . -I /opt/X11/include -L /opt/X11/lib -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Aquarium.cpp -I . -I /opt/X11/include

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Bestiole.cpp -I . -I /opt/X11/include

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Milieu.cpp -I . -I /opt/X11/include

BestioleDecorator.o : BestioleDecorator.h BestioleDecorator.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c BestioleDecorator.cpp -I . -I /opt/X11/include

EyesDecorator.o : EyesDecorator.h EyesDecorator.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c EyesDecorator.cpp -I . -I /opt/X11/include

EarsDecorator.o : EarsDecorator.h EarsDecorator.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c EarsDecorator.cpp -I . -I /opt/X11/include

Nageoires.o : Nageoires.h Nageoires.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Nageoires.cpp -I . -I /opt/X11/include

Carapace.o : Carapace.h Carapace.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Carapace.cpp -I . -I /opt/X11/include

Camouflage.o : Camouflage.h Camouflage.cpp
	g++ -Wall -std=c++11 -DCIMG_USE_VSNPRINTF -c Camouflage.cpp -I . -I /opt/X11/include

clean:
	rm -rf *.o main
