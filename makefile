# Ahnaf Raihan
# Dijkstra

all:	Dijkstra

Dijkstra:	main.o
	g++  main.o -o Dijkstra

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o Dijkstra

