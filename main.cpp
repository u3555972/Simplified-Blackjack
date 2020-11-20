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
  fin.open(name);
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
  ifstream fin;
  fin.open(name);
  char n[50];
  for (int i=0; i<name.length(); ++i){
    n[i]=name[i];
  }
  remove(n);
  ofstream fout;
  fout.open(name);
  fout<<name<<'\n'<<"10000"<<'\n'<<'\n'<<"10000"<<'\n'<<endl;
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
  fin.open(name);
  //if it doesnt, create a new file
  if (fin.fail()){
    newg(name);
  }
  else {
    cout<<"You have a saved game. Do you want to continue (C) or start a new game (N): ";
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

return 0;
}
