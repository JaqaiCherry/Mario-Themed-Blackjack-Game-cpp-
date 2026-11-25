#include <iostream>
#include "Deck.hpp"
#include <algorithm>
#include <random>

Deck::Deck() {
    std::vector<std::string> suits {"Hearts", "Diamonds", "Spades", "Clubs"};
    std::vector<std::string> ranks {"2", "3", "4","5","6","7","8","9","10","Ace","Jack","Queen","King"};

for (const std::string& suit : suits) {
    for (const std::string& rank : ranks) {
        int value = 10;
        if ( rank == "Jack" || rank =="Queen" || rank == "King"){
            value = 10;
        }
        else if(rank == "Ace") {
           value = 11;
        }

        else {
             value = std::stoi(rank);
        }
        cards.push_back(Card(rank + " of " + suit, value));
    }

}

cards.push_back(Card("Star Card", 0, CardType::Star));
cards.push_back(Card("Swap Card", 0, CardType::Swap));
cards.push_back(Card("Bowser Card", 0, CardType::Bowser));

}

void Deck::shuffleCard() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle ( cards.begin(), cards.end(), rng);
}



int Deck::remainingCard() const { 
    return cards.size(); 
   
}

Card Deck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    
    return topCard;
}



