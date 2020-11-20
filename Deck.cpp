#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void build_deck(string *deck) {
  int counter = 0;
  //string* deck = new string[52];
  string rank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  string suit[4] = {"\u2660", "\u2661", "\u2662", "\u2663"};
  for (int i=0; i<13; i++) {
    for (int j=0; j<4; j++) {
      deck[counter] = rank[i] + suit[j];
      counter ++;
    }
  }
  //return deck;
}

void shuffle_deck(string *deck) {
  srand(time(0));
  for (int card=0; card<52; card++) {
    int shuffle = card + (rand() % (52 - card));
    swap(deck[card], deck[shuffle]);
  }
  //return deck;
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
  //cout << "Hand Value: " << p_hand_value << endl;
  // if (p_hand_value > 21) {
  //   cout << "Busted! You lose..." << endl;
  //   //return 'L';
  // }
  if (p_hand_value == 21) {
    cout << "Blackjack! You win..." << endl;
    //return 'W';
  }
  else if (p_hand_value > c_hand_value) {
    cout << "Your hand of " << p_hand_value << " is greater than the Dealer's hand of " << c_hand_value << endl;
    cout << "You Win!" << endl;
    //return 'W';
  }
  else if (c_hand_value > 21) {
    cout << "Dealer busted! You win!" << endl;
  }
  else if (c_hand_value > p_hand_value) {
    cout << "The Dealer's hand of " << c_hand_value << " is greater than your hand of " << p_hand_value << endl;
    cout << "You lose..." << endl;
  }
  //return 0;
}

int main() {
  char newgame = 'Y';
  while (newgame == 'Y') {
    string *deck = new string[52];
    string *player_deck = new string[5];
    string *comp_deck = new string [5];
    int p_counter = 0;
    int c_counter = 0;

    build_deck(deck);
    shuffle_deck(deck);

    cout << "Your Hand:" << endl;
    add_to_player_deck(player_deck, p_counter, deck);
    add_to_player_deck(player_deck, p_counter, deck);
    int p = 0;
    while (p < p_counter) {
      cout << player_deck[p];
      if (p < (p_counter-1)) {
        cout << " ";
      }
      p += 1;
    }
    int p_hand_value = player_sum(player_deck, p_counter);
    cout << endl;
    cout << "Hand Value: " << p_hand_value << endl;
    cout << endl;

    cout << "Dealer draws 2 cards..." << endl;
    add_to_comp_deck(comp_deck, c_counter, deck);
    add_to_comp_deck(comp_deck, c_counter, deck);
    // int c = 0;
    // while (c < c_counter) {
    //   cout << comp_deck[c];
    //   if (c < (c_counter-1)) {
    //     cout << " ";
    //   }
    //   c+= 1;
    // }
    // cout << endl;
    int c_hand_value = comp_sum(comp_deck, c_counter);
    cout << endl;

    bool skip = true, busted = false;
    if (p_hand_value > 21) {
      cout << "Busted! You lose..." << endl;
    }

    else if (p_hand_value == 21) {
      cout << "Blackjack! You win!" << endl;
    }

    else if (c_hand_value == 21) {
      cout << "Dealer has a Blackjack! You lose..." << endl;
    }

    else if (c_hand_value > 21) {
      cout << "Dealer busted! You win!" << endl;
    }

    else {
      char decision = 'Y';
      while (decision == 'Y') {
        cout << "Do you want to draw a card (hit) (Y/N)?: ";
        cin >> decision;
        if (decision == 'Y') {
          add_to_player_deck(player_deck, p_counter, deck);
          int p = 0;
          while (p < p_counter) {
            cout << player_deck[p];
            if (p < (p_counter-1)) {
              cout << " ";
            }
            p += 1;
          }
          int p_hand_value = player_sum(player_deck, p_counter);
          cout << endl;
          cout << "Hand Value: " << p_hand_value << endl;
          //cout << p_hand_value << endl;
          if (p_hand_value > 21) {
            cout << "Busted! You lose..." << endl;
            decision = 'N';
            skip = false;
            busted = true;
          }
        }
      }
    }
    if (skip) {
      if (c_hand_value < 17) {
        cout << "Dealer draws a card..." << endl;
        add_to_comp_deck(comp_deck, c_counter, deck);
      }
      p_hand_value = player_sum(player_deck, p_counter);
      cout << endl;
      cout << "Dealer's Hand:" << endl;
      int c = 0;
      while (c < c_counter) {
        cout << comp_deck[c];
        if (c < (c_counter-1)) {
          cout << " ";
        }
        c+= 1;
      }
      cout << endl;
      c_hand_value = comp_sum(comp_deck, c_counter);
      cout << "Dealer's Hand Value: " << c_hand_value << endl;
      cout << endl;
      determine_w_l(p_hand_value, c_hand_value);
      cout << endl;
    }

    else if (busted == true) {
      cout << endl;
      cout << "Dealer's Hand:" << endl;
      int c = 0;
      while (c < c_counter) {
        cout << comp_deck[c];
        if (c < (c_counter-1)) {
          cout << " ";
        }
        c+= 1;
      }
      cout << endl;
      c_hand_value = comp_sum(comp_deck, c_counter);
      cout << "Dealer's Hand Value: " << c_hand_value << endl;
      cout << endl;
    }

    else {
      if (c_hand_value < 17) {
        cout << "Dealer draws a card..." << endl;
        add_to_comp_deck(comp_deck, c_counter, deck);
      }
      //p_hand_value = player_sum(player_deck, p_counter);
      cout << endl;
      cout << "Dealer's Hand:" << endl;
      int c = 0;
      while (c < c_counter) {
        cout << comp_deck[c];
        if (c < (c_counter-1)) {
          cout << " ";
        }
        c+= 1;
      }
      cout << endl;
      c_hand_value = comp_sum(comp_deck, c_counter);
      cout << "Dealer's Hand Value: " << c_hand_value << endl;
      cout << endl;
    }
    cout << "Do you want to play again (Y/N)?: ";
    cin >> newgame;
  }
  cout << endl;
  cout << "Thank you for playing!" << endl;
}

  // int c = 0;
  // while (c < c_counter) {
  //   cout << comp_deck[c];
  //   if (c < (c_counter-1)) {
  //     cout << " ";
  //   }
  //   c+= 1;
  // }
  // cout << endl;
  // c_hand_value = comp_sum(comp_deck, c_counter);
  // cout << "Dealer's Hand Value: " << c_hand_value;




  // for (int card=0; card<52; card++) {
  //   cout<< deck[card] << endl;
  // }

  // int p_counter = 0;
  // for (int p_cards=0; p_cards<2; p_cards++) {
  //   string t = deal_cards(deck);
  //   player_deck[p_cards] = t;
  //   p_counter ++;
  // }

  // int c_counter = 0;
  // for (int c_cards=0; c_cards<2; c_cards++) {
  //   string t = deal_cards(deck);
  //   comp_deck[c_cards] = t;
  //   c_counter ++;
  // }

  //string *d_ptr = build_deck(deck);
  // for (int k=0; k<52; k++) {
  //   cout << d_ptr[k] << endl;
  // }

  //string *ds_ptr = shuffle_deck(d_ptr);
  // for (int x=0; x <52; x++) {
  //   cout << ds_ptr[x] << endl;
  // }

  // string t = deal_cards(ds_ptr);
  // cout << t;
  //
  // for (int y=0; y<51; y++) {
  //   cout << deck[y] << endl;
  // }

//   string deck[52];
//   int counter = 0;
//   string rank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
//   string suit[4] = {"\u2660", "\u2661", "\u2662", "\u2663"};
//   for (int i=0; i<13; i++) {
//     for (int j=0; j<4; j++) {
//       deck[counter] = rank[i] + suit[j];
//       counter ++;
//     }
//   }
//   for (int k=0; k<52; k++) {
//     cout << deck[k] << endl;
//   }
