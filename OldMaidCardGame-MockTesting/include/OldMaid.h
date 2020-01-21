/**
* @author Mathew Richards
* @date 2019-09
* @brief Header for the OldMaid class
*/

#ifndef OLDMAID_H
#define OLDMAID_H
#include "Cards.h"
#include "Hand.h"
#include "Deck.h"
#include "OldMaidUI.h"
#include <vector>

using std::vector;

class OldMaid {
 public:
    OldMaid();
    bool gameOver = false;
    virtual ~OldMaid();
    int game(int players, int playerTurn, OldMaidUI *u, Deck *d, Hand *h);
    int numberOfPlayers(OldMaidUI u);
    bool sumSize(int players, vector<vector<Cards*> > remainingCards);
 protected:
 private:
};

#endif // OLDMAID_H
