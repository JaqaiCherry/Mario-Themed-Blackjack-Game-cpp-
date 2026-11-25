#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include "Card.hpp"


class Player {

public:
std::string name;

std::vector<Card> hand;

int coins;

 Player(std::string playerName, int startingCoins = 20);

 void addCard(const Card& card);

 void clearHand();

 int calculateScore() const;

 bool isBusted() const;

};

#endif 

