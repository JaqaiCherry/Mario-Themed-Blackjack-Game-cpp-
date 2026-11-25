#include <iostream>
#include "Player.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include <algorithm>
using namespace std;

void printHand(const Player& player) {
   
    std::cout << "Player Name: " << player.name << endl;
    std::cout << "Player Coins: " << player.coins << endl;
    
    for(const Card& c : player.hand){
       std::cout << "Player Hand: " << c.name << "\n";
    }

    std::cout << "Total Score: " << player.calculateScore() <<"\n" "\n";

}

void dealCardWithTwist(Deck& deck, Player& current, Player& opponent){
    
    Card drawn = deck.drawCard();
    std::cout << " Card Drew: " << current.name << " " << drawn.name << "\n";
    current.addCard(drawn);

if(drawn.type == CardType::Bowser) {
    current.coins -= 5;
}

else if(drawn.type == CardType::Swap){
    std::swap(current.hand, opponent.hand);
}

else if(drawn.type == CardType::Star){
    std::cout << " Star Power Activated!!" << "\n";
}

}

Player* determineWinner(Player& human, Player& dealer){
    if (human.isBusted()){ // Note: All if statement conditions must be wrapped into a parenthesis
        return &dealer;
    }

    else if (dealer.isBusted()) {
        return&human;
    }
    
    else if (human.calculateScore() > dealer.calculateScore()){
        return &human;
    }

    else if (dealer.calculateScore() > human.calculateScore()){
        return &dealer;
    }

    else {
        return nullptr;
    }
}


int main() {
    Deck deck;
    deck.shuffleCard();
    Player human( "Mario", 20); 
    Player dealer("Bowser", 20 );   
    dealCardWithTwist(deck, human, dealer);
    dealCardWithTwist(deck, human, dealer);
    dealCardWithTwist(deck, dealer, human);
    dealCardWithTwist(deck, dealer, human);

    Player* activePlayer = &human;

    while(activePlayer == &human && !human.isBusted()){
        printHand(*activePlayer);
        
        char choice;
        std::cout << "Hit(h) or Stand(s): " << "\n";
        cin >> choice;

        if(choice == 'h' || choice == 'H') {
            dealCardWithTwist(deck, *activePlayer, dealer);

        }

        else {
            activePlayer = &dealer;
        }


    }
    
    if(!human.isBusted()){
        std::cout << "\n ---- Bowser's Turn ---- \n";
    
    while(activePlayer->calculateScore() < 17){
        dealCardWithTwist(deck, *activePlayer, human);   
    }
    }

    std::cout << "\n ---- Final Results ---- \n";
    printHand(human);
    printHand(dealer);

    Player* winner = determineWinner(human, dealer);

    if(winner == nullptr ){
        std::cout << " It's a Tie!! " << "\n";
    }

    else {
        std::cout << winner->name << "wins the round and earns 10 coins! " << "\n";    
        winner->coins += 10;
        }



    return 0;
}