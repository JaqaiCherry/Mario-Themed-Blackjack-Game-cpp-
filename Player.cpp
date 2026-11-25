#include <iostream>
#include "Player.hpp"
#include <string>
#include <vector>

Player::Player(std::string playerName, int startingCoins) 
    : name(playerName), coins(startingCoins) {
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

bool Player::isBusted() const {
    return calculateScore() > 21;
}

int Player::calculateScore() const {
    int totalScore = 0;
    int aceCount = 0;
    bool hasStarCard = false;
    
    for (const Card& card : hand) {
        totalScore += card.value;
        if(card.value == 11){
            aceCount++;

        }

        if (card.type == CardType::Star){
            hasStarCard = true;
        }
    }

    while (totalScore > 21 && aceCount > 0) {
        totalScore -=10;
        aceCount --;
    }

    if (hasStarCard == true) {
        totalScore = 21;
    }

    return totalScore;
}


    

   
