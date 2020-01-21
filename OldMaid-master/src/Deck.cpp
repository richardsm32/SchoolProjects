/**
* @author Mathew Richards
* @date 2019-10
* @brief Implementation of the Deck class
*/

#include "Deck.h"
#include "Cards.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;

Deck::Deck() {
    //ctor
}

Deck::~Deck() {
    //dtor
}

vector<Cards*> Deck::generateDeck() {
    vector<Cards*> freshDeck;
    Cards* cardPTR;
    for (int i=1; i <= 13; i++)
        for (int j=0; j < 4; j++)
            freshDeck.push_back(new Cards(i, static_cast<Suit>(j)));
    unsigned int a = 0; //counter for use after
    //remove the Queen of Hearts
    for (&a; a < freshDeck.size(); a++) {
        if (freshDeck[a]->value == 12 && freshDeck[a]->suit == HEARTS)
            break;
    }
    cardPTR = freshDeck[a];
    //put the Queen of Hearts in the discard pile
    discardPile.push_back(std::move(freshDeck[a]));
    freshDeck.erase(freshDeck.begin()+a);
    delete cardPTR;
    return freshDeck;
}

vector<Cards*> Deck::shuffleDeck(vector<Cards*> freshDeck) {
    std::random_device r;
    std::shuffle(freshDeck.begin(), freshDeck.end(), r);
    vector<Cards*> shuffledDeck = freshDeck;
    return shuffledDeck;
}

vector<vector<Cards*> > Deck::Deal(int players, vector<Cards*> shuffledDeck) {
    //create "players" number of vectors within a vector
    vector<vector<Cards*> > freshHands(players);
    //deal cards to each vector in allHands
    //use mainDeck.size as limit to dealing out
    for (int i=0; i < shuffledDeck.size(); i++)
        freshHands[i % players].push_back(shuffledDeck[i]);
    return freshHands;
}
