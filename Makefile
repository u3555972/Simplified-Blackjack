Make_deck_test.o: Make_deck_test.cpp Make_deck_test.h
	g++ -c Make_deck_test.cpp

main.o: main.cpp Make_deck_test.h
	g++ -c main.cpp

game: main.o Make_deck_test.o
	g++ main.o Make_deck_test.o -o game
