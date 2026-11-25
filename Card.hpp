#ifndef CARD_HPP
#define CARD_HPP
#include <string>

enum class CardType {

    Normal,
    Star,
    Bowser,
    Swap

};

class Card {
public:

    std::string name;
    int value;
    CardType type;
    Card(std::string cardName, int cardValue, CardType cardType = CardType::Normal) : name(cardName), type(cardType), value(cardValue) {}

};

#endif