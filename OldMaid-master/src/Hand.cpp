/**
* @author Mathew Richards
* @date 2019-10
* @brief Implementation of the Hand class
*/

#include "Hand.h"
#include "Deck.h"
#include "Cards.h"
#include "OldMaid.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <limits>

bool comp(Cards* a, Cards* b) {
    return a->getValue() <= b->getValue();
}

Hand::Hand() {
    //ctor
}

Hand::~Hand() {
    //dtor
}

vector<vector<Cards*> > Hand::initPickPairs(
        int players, Deck *d, vector<vector<Cards*> > freshHands) {
    vector<vector<Cards*> > playerHands(players);
    //sort hands to find pairs
    for (int i=0; i < players; i++) {
        sort(freshHands[i].begin(), freshHands[i].end(),
              comp);
        //pick out the pairs in each hand
        for (unsigned int j=0; j < freshHands[i].size()-1; j++) {
            //if a card has the same value as the next one
            if (freshHands[i][j]->getValue() ==
                freshHands[i][j+1]->getValue()) {
                d->discardPile.push_back(freshHands[i][j]);
                d->discardPile.push_back(freshHands[i][j+1]);
                j++;
            } else {//no pairs
                playerHands.at(i).push_back(freshHands[i][j]);
            }
        }
        //reshuffle the hands
        std::random_device r;
        std::shuffle(playerHands[i].begin(), playerHands[i].end(), r);
    }
    return playerHands;
}

vector<vector<Cards*> > Hand::pickCard(Deck *d,
                                       int players,
                                       vector<vector<Cards*> > playerHands) {
    bool valid = false;
    int theirHandSize = playerHands[players-1].size();
    int yourHandSize = playerHands[0].size();
    vector<vector<Cards*> > smallerHands(players);
    int selection;
    do {
        std::cin >> selection;
        selection--;
        if (selection >= 0 && selection < theirHandSize) {
            playerHands[0].push_back(playerHands[players-1][selection]);
            playerHands[players-1].erase(playerHands[players-1].begin()+
                                         selection);
            //need to sort player 1's hand
            sort(playerHands[0].begin(), playerHands[0].end(),
                  comp);
            //CHECK FOR PAIRS
            yourHandSize = playerHands[0].size();
            for (int i=0; i < yourHandSize; i++) {
                if (i == yourHandSize-1) {
                    smallerHands[0].push_back(playerHands[0][i]);
                } else {
                    if (playerHands[0][i]->getValue() ==
                        playerHands[0][i+1]->getValue()) {
                        d->discardPile.push_back(playerHands[0][i]);
                        d->discardPile.push_back(playerHands[0][i+1]);
                        i++;
                    } else {//no pairs
                        smallerHands[0].push_back(playerHands[0][i]);
                    }
                }
            }
            valid = true;
        } else /*selection was invalid, try again*/ {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid card selection" << std::endl;
            std::cout << "Please try again" << std::endl;
        }
    } while (!valid);
    //COPY THE REST OF THE CARDS TO smallerHands
    //i=1 because player hand is already done
    for (int i=1; i < players; i++) {
        smallerHands[i] = playerHands[i];
    }
    //Shuffle the cards so selection is random
    std::random_device r;
    for (int i=0; i < players; i++) {
        std::shuffle(smallerHands[i].begin(), smallerHands[i].end(), r);
    }
    return smallerHands;
}

vector<vector<Cards*> > Hand::aiPickCard(Deck *d,
                                         int players,
                                         int playerTurn,
                                         vector<vector<Cards*> > playerHands) {
    int takeCardFrom = playerTurn-1;
    int handSize = playerHands[takeCardFrom].size();
    vector<vector<Cards*> > smallerHands(players);
    std::uniform_int_distribution<int> randomCard(0, handSize-1);
    std::random_device r;
    int selection = randomCard(r);
    if (selection >= 0 && selection < handSize) {
        playerHands[playerTurn].push_back(playerHands[takeCardFrom]
                                          [selection]);
        playerHands[takeCardFrom].erase(playerHands[takeCardFrom].
                                        begin()+selection);
        //need to sort players hand
        sort(playerHands[playerTurn].begin(), playerHands[playerTurn].end(),
              comp);
        for (unsigned int i=0; i < playerHands[playerTurn].size(); i++) {
            if (i == playerHands[playerTurn].size()-1) {
                smallerHands[playerTurn].push_back(playerHands[playerTurn][i]);
            } else {
                if (playerHands[playerTurn][i]->getValue() ==
                    playerHands[playerTurn][i+1]->getValue()) {
                    d->discardPile.push_back(playerHands[playerTurn][i]);
                    d->discardPile.push_back(playerHands[playerTurn][i+1]);
                    i++;
                } else {//not a pair
                    smallerHands[playerTurn].push_back
                    (playerHands[playerTurn][i]);
                }
            }
        }
    }
    //COPY THE REST OF THE CARDS FROM THE VECTOR TO NEW ONE
    for (int i=0; i < players; i++) {
        if (i == playerTurn)
            continue;
        else
            smallerHands[i] = playerHands[i];
    }
    //Shuffle the cards so selection is random
    for (int i=0; i < players; i++) {
        std::shuffle(smallerHands[i].begin(), smallerHands[i].end(), r);
    }
    return smallerHands;
}
