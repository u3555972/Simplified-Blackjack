FLAGS = -pedantic-errors -std=c++11

deck.o: deck.cpp deck.h
	g++ $(FLAGS) -c deck.cpp

main.o: main.cpp deck.h
	g++ $(FLAGS) -c main.cpp
	
savegame.o: savegame.cpp savegame.h
	g++ $(FLAGS) -c savegame.cpp

game: main.o deck.o
	g++ main.o deck.o -o game

.PHONY: clean

clean:
	rm -f game main.o deck.o
