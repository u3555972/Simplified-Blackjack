#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "deck.h"
using namespace std;

void displaycurrent(string name){
  string moneyp, moneyc;
  //prints name and total money of player and computer
  ifstream fin;
  fin.open(name+".txt");
  cout<<"Name: ";
  fin>>name;
  cout<<name<<'\n';
  cout<<"Total money: $";
  fin>>moneyp;
  cout<<moneyp<<'\n';
  cout<<"The computer has $";
  fin>>moneyc;
  cout<<moneyc<<endl;
  fin.close();
}

void newg(string name){
  //new game opens deletes originally saved game and gives computer $10000
  char n[50];
  for (int i=0; i<name.length(); ++i){
    n[i]=name[i];
  }
  n[name.length()]='.';
  n[name.length()+1]='t';
  n[name.length()+2]='x';
  n[name.length()+3]='t';
  remove(n);
  ofstream fout;
  fout.open(name+".txt");
  fout<<name<<'\n'<<"10000"<<'\n'<<"10000"<<'\n'<<endl;
  fout.close();
  displaycurrent(name);
}

int main() {
  string name, money;
  char saved;
  cout<<"Welcome to Blackjack!"<<endl;
  cout<<"Instructions:"<<endl;
  cout<<"The aim of the game is to get a total as close to the number 21 (inclusively) as possible. Two regular cards will be dealt to the player and the computer. The cards 2-10 are worth their own numbers while \'J\', \'Q\' and \'K\' are worth 10 each. Furthermore, \'A\' can either be worth 1 or 11 points depending on the users choice. At the beginning of each round, the player can choose to either ask for 1 more card to increase their total points or they can choose to stay, keeping their hand. The player with the closest total points to 21 or has the sum of 21 with the lowest number of cards wins! Unfortunately, if the player's total does surpass 21, they are \"busted\" (loses the match)"<<endl;
  cout<<endl;
  cout<<"1) Each player starts with $10,000"<<endl;
  cout<<"2) The minimum betting for each player is $1,000 per match"<<endl;
  cout<<"3) After recieving the player recieves their cards, they may choose to raise their betting amount"<<endl;
  cout<<"4) After a player raises, the player must match the raise and the round commences. If the player is unable to match the raise, they lose the round immediately"<<endl;
  cout<<"5) If a round is matched, players can either request another card, reveal their cards or fold (forfeit match)"<<endl;
  cout<<"6) If a player cannot pay the minimum bet or loses all their money at the end of a round, they lose the match and the game ends."<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"What is your name? ";
  cin>>name;
  //check if file exists
  ifstream fin;
  fin.open(name+".txt");
  //if it doesnt, create a new file
  if (fin.fail()){
    newg(name);
  }
  else {
    cout<<"You have a saved game. Do you want to continue (C) or overwrite and start a new game (N): ";
    cin>>saved;
    if (saved=='C'){
      displaycurrent(name);
    }
    else if (saved=='N') {
      newg(name);
    }
    else {
      cout<<"Answer invalid. Please try again.";
      cin>>saved;
    }
  }
  fin.close();
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
