#ifndef DECK_HPP
#define DECK_HPP
#include "Card.hpp"
#include <string>
#include <vector>

class Deck {

private:
    std::vector<Card> cards;

public: 
    Deck();
    void shuffleCard();
    int remainingCard() const;
    Card drawCard();






};
#endif