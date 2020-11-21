#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;

void displaycurrent(string name){
  string moneyp, moneyc;
  //prints name and total money of player and computer
  //input of the string name such that name.txt can be opened
  //output name, amount of money player has and amount of money dealer has
  cout<<"Your current game:"<<endl;
  ifstream fin;
  fin.open(name+".txt");
  cout<<"Name: ";
  fin>>name;
  cout<<name<<endl;
  cout<<"Total money: $";
  fin>>moneyp;
  cout<<moneyp<<'\n';
  cout << endl;
  cout<<"The Dealer has $";
  fin>>moneyc;
  cout<<moneyc<<endl;
  cout<<endl;
  fin.close();
}

void newg(string name){
  //new game opens deletes originally saved game and gives computer $10000
  //input of name such that the origianlly saved file of name.txt is deleted and a new one is created.
  //inside the file is name, and $10000 to each player
  char n[50];
  for (int i=0; i<name.length(); ++i){
    n[i]=name[i];
  }
  n[name.length()]='.';
  n[name.length()+1]='t';
  n[name.length()+2]='x';
  n[name.length()+3]='t';
  remove(n); //deletes existing saved game
  ofstream fout;
  fout.open(name+".txt");
  fout<<name<<'\n'<<"10000"<<'\n'<<"10000"<<'\n'<<endl;
  fout.close();
  displaycurrent(name); //displays the file contents
}
