deck.o: deck.cpp deck.h
	g++ -c deck.cpp

main.o: main.cpp deck.h
	g++ -c main.cpp

game: main.o deck.o
	g++ main.o deck.o -o game
