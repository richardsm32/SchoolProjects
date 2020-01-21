/**
* @author Mathew Richards
* @date 2019-09
* @brief Header for the Deck class
*/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Cards.h"
using std::vector;

class Deck {
 public:
    Deck();
    virtual ~Deck();
    virtual vector<vector<Cards*> > Deal(int players,
            vector<Cards*> shuffledDeck);
    virtual vector<Cards*> generateDeck();
    virtual vector<Cards*> shuffleDeck(vector<Cards*> freshDeck);
    int players;
    vector<Cards*> discardPile;
 protected:
 private:
};

#endif // DECK_H
