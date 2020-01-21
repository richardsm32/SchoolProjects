/**
* @author Mathew Richards
* @date 2019-10
* @brief Implementation of the OldMaid class
*/

#include "OldMaid.h"
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
#include "OldMaidUI.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>


bool comp1(Cards* a, Cards* b) {
    return a->getValue() <= b->getValue();
}

OldMaid::OldMaid() {
    //ctor
}

OldMaid::~OldMaid() {
    //dtor
}

int OldMaid::game(int players, int playerTurn, OldMaidUI *u, Deck *d, Hand *h) {
    //welcome message is handled in main when getting number of players
    std::random_device generator;
    std::uniform_int_distribution<int> playerRange(0, players-1);
    playerTurn = 0;
    //UI to prep game
    u->getReady(players);
    //make the deck and remove the Queen of Hearts
    vector<Cards*> oldMaidDeck = d->generateDeck();
    //shuffle the deck
    oldMaidDeck = d->shuffleDeck(oldMaidDeck);
    //create each hand and deal the cards
    vector<vector<Cards*> > oldMaidHands = d->Deal(players, oldMaidDeck);
    //UI announce sort and discard pairs
    u->initPairs();
    sleep(1);
    //sort hands and delete all initial pairs
    oldMaidHands = h->initPickPairs(players, d, oldMaidHands);
    u->startGame(playerTurn);
    do { /*Main Game Loop*/
        //u->discardCheck(d);
        //reset playerTurn if necessary
        if (playerTurn >= players)
            playerTurn = 0;
        if (playerTurn == 0) /*Human's Turn*/ {
            int takeCardFrom = players-1; //take from previous player
            int theirHandSize = oldMaidHands[takeCardFrom].size();
            int yourHandSize = oldMaidHands[playerTurn].size();
            //sort before displaying player hand
            sort(oldMaidHands[0].begin(), oldMaidHands[0].end(),
              comp1);
            u->pTurn(takeCardFrom, theirHandSize, oldMaidHands);
            if (theirHandSize == 0) {
                u->emptyHand();
            } else {
                oldMaidHands = h->pickCard(d, players,
                                          oldMaidHands);
                if (oldMaidHands[0].size() < yourHandSize)
                    u->announcePair();
                u->pEndTurn(takeCardFrom, oldMaidHands);
            }
            gameOver = sumSize(players, oldMaidHands);
            playerTurn++;
        } else {
            int takeCardFrom = playerTurn-1;
            int aiHand = oldMaidHands[playerTurn].size();
            u->aiStartTurn(playerTurn, aiHand);
            if (oldMaidHands[takeCardFrom].size() == 0) {
                u->emptyHand();
            } else {
                oldMaidHands = h->aiPickCard(d, players,
                                            playerTurn, oldMaidHands);
                if (oldMaidHands[playerTurn].size() < aiHand)
                    u->announcePair();
                u->aiEndTurn(playerTurn, takeCardFrom, oldMaidHands);
            }
            gameOver = sumSize(players, oldMaidHands);
            playerTurn++;
            }
        } while (!gameOver);
    if (gameOver) {
        int loser;
        for (unsigned int i=0; i < players; i++) {
            if (oldMaidHands[i].size() == 1)
                loser = i;
        }
        u->endGame(loser);
    }
    return 0;
}

int OldMaid::numberOfPlayers(OldMaidUI u) {
    u.welcome();
    int players;
    bool getInput;
    std::cin >> players;
    do {
        if (players > 0 && players < 6) {
            getInput = true;
            return players;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            u.invalid(); //UI informs of wrong input
            std::cin >> players;
        }
    } while (!getInput);
}

bool OldMaid::sumSize(int players, vector<vector<Cards*> > remainingCards) {
    int sum = 0;
    for (int i=0; i < players; i++)
        sum += remainingCards[i].size();
    if (sum <= 1)
        return true;
    else
        return false;
}
