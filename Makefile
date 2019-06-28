CPP = g++
CPPFLAGS = -Wall

OBJ = main.o abc.o bee.o tsplib.o

main: $(OBJ)
	$(CPP) $(OBJ) -o main

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o

abc.o: abc.cpp abc.hpp
	$(CPP) -c abc.cpp -o abc.o

bee.o: bee.cpp bee.hpp
	$(CPP) -c bee.cpp -o bee.o

tsplib.o: tsplib.cpp tsplib.hpp
	$(CPP) -c tsplib.cpp -o tsplib.o

all: main

clean:
	find . -type f | xargs touch
	rm -f *.o
