/**
* @author Mathew Richards
* @date 2019-09
* @brief Header for the OldMaidUI class
*/

#ifndef OLDMAIDUI_H
#define OLDMAIDUI_H

#include "Cards.h"
#include "Deck.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

class OldMaidUI {
 public:
    OldMaidUI();
    virtual ~OldMaidUI();
    void welcome();
    void invalid();
    void getReady(int players);
    void initPairs();
    void startGame(int playerTurn);
    void pTurn(int takeFrom,
               int takeSize,
               vector<vector<Cards*> > currentHands);
    void pEndTurn(int takeCardFrom,
                  vector<vector<Cards*> > currentHand);

    void printHand(vector<vector<Cards*> > currentHand);
    void aiStartTurn(int playerTurn, int aiHand);
    void aiEndTurn(int playerTurn, int takeCardFrom,
                   vector<vector<Cards*> > currentHand);
    void discardCheck(Deck *d);
    void emptyHand();
    void announcePair();
    void endGame(int loser);
    string suitToStr(Cards* currentCard);
    string valueToStr(Cards* currentCard);

 protected:
    //prevent a style error
 private:
};

#endif // OLDMAIDUI_H
