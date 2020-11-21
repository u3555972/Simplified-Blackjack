//deck.h
#ifndef DECK_H
#define DECK_H

void build_deck(std::string *deck);
void shuffle_deck(std::string *deck);
std::string deal_cards(std::string *deck);
void add_to_player_deck(std::string *player_deck, int &p_counter, std::string *deck);
void add_to_comp_deck(std::string *comp_deck, int &c_counter, std::string *deck);
int player_sum(std::string *player_deck, int &p_counter);
int comp_sum(std::string *comp_deck, int &c_counter);
char determine_w_l(int p_hand_value, int c_hand_value);

#endif
