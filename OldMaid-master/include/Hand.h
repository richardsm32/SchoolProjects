/**
* @author Mathew Richards
* @date 2019-09
* @brief Header for the Hand class
*/

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Cards.h"
#include "Deck.h"

class Hand {
 public:
    Hand();
    Hand(vector<vector<Cards*> > allHands);
    virtual ~Hand();
    //method to delete pairs after initial deal
    virtual vector<vector<Cards*> > initPickPairs(int players, Deck *d,
                                          vector<vector<Cards*> > freshHands);
    //pick card from prev player
    virtual vector<vector<Cards*> > pickCard(Deck *d, int players,
                                     vector<vector<Cards*> > playerHands);
    virtual vector<vector<Cards*> > aiPickCard(Deck *d,
                                       int players,
                                       int playerTurn,
                                       vector<vector<Cards*> > playerHands);
    int playerTurn; //count to indicate whose turn it is
    std::vector<Cards*> discardPile;
 protected:
 private:
};

#endif // HAND_H
