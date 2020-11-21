FLAGS = -pedantic-errors -std=c++11

deck.o: deck.cpp deck.h
	g++ $(FLAGS) -c deck.cpp

savegame.o: savegame.cpp savegame.h
	g++ $(FLAGS) -c savegame.cpp

main.o: main.cpp deck.h savegame.h
	g++ $(FLAGS) -c main.cpp

game: main.o deck.o savegame.o
	g++ main.o deck.o savegame.o -o game

.PHONY: clean

clean:
	rm -f game main.o deck.o savegame.o
