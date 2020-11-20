#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function for building deck
void build_deck(string *deck) {
  int counter = 0;
  string rank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  string suit[4] = {"\u2660", "\u2661", "\u2662", "\u2663"};
  for (int i=0; i<13; i++) {
    for (int j=0; j<4; j++) {
      deck[counter] = rank[i] + suit[j];
      counter ++;
    }
  }
}

void shuffle_deck(string *deck) {
  srand(time(0));
  for (int card=0; card<52; card++) {
    int shuffle = card + (rand() % (52 - card));
    swap(deck[card], deck[shuffle]);
  }
}

string deal_cards(string *deck) {
  string card = deck[0];
  string* temp_deck = new string[52];
  deck[0] = "0";

  for (int i = 1; i < 52; i++) {
    deck[i-1] = deck[i];
  }
  return card;
}

void add_to_player_deck(string *player_deck, int &p_counter, string *deck) {
  string add_card = deal_cards(deck);
  player_deck[p_counter] = add_card;
  p_counter++;
}

void add_to_comp_deck(string *comp_deck, int &c_counter, string *deck) {
  string add_card = deal_cards(deck);
  comp_deck[c_counter] = add_card;
  c_counter++;
}

int player_sum(string *player_deck, int &p_counter) {
  string temp_deck[5];
  int value_deck=0;
  for (int cards = 0; cards < p_counter; cards++) {
    temp_deck[cards] = player_deck[cards][0];
  }
  for (int value = 0; value < p_counter; value ++) {
    if (temp_deck[value] == "J" || temp_deck[value] == "Q" || temp_deck[value] == "K" || temp_deck[value] == "1") {
      value_deck += 10;
    }
    else if (temp_deck[value] == "A") {
      value_deck += 11;
    }
    else {
      value_deck += stoi(temp_deck[value]);
    }
  }
  return value_deck;
}

int comp_sum(string *comp_deck, int &c_counter) {
  string temp_deck[5];
  int value_deck=0;
  for (int cards = 0; cards < c_counter; cards++) {
    temp_deck[cards] = comp_deck[cards][0];
  }
  for (int value = 0; value < c_counter; value ++) {
    if (temp_deck[value] == "J" || temp_deck[value] == "Q" || temp_deck[value] == "K" || temp_deck[value] == "1") {
      value_deck += 10;
    }
    else if (temp_deck[value] == "A") {
      value_deck += 11;
    }
    else {
      value_deck += stoi(temp_deck[value]);
    }
  }
  return value_deck;
}

void determine_w_l(int p_hand_value, int c_hand_value) {
  if (p_hand_value == 21) {
    cout << "Blackjack! You win..." << endl;
  }
  else if (p_hand_value > c_hand_value) {
    cout << "Your hand of " << p_hand_value << " is greater than the Dealer's hand of " << c_hand_value << endl;
    cout << "You Win!" << endl;
  }
  else if (c_hand_value > 21) {
    cout << "Dealer busted! You win!" << endl;
  }
  else if (c_hand_value > p_hand_value) {
    cout << "The Dealer's hand of " << c_hand_value << " is greater than your hand of " << p_hand_value << endl;
    cout << "You lose..." << endl;
  }
}
