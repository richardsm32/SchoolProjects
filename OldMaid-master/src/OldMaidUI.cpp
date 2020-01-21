/**
* @author Mathew Richards
* @date 2019-10
* @brief Implementation of the OldMaidUI class
*/
#include "OldMaidUI.h"
#include "OldMaid.h"
#include "Cards.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;

OldMaidUI::OldMaidUI() {
    //ctor
}

OldMaidUI::~OldMaidUI() {
    //dtor
}
void OldMaidUI::welcome() {
    cout << "*********************************************" << endl;
    cout << "Welcome to Old Maid!!" << endl;
    cout << "Please enter the number of players (2 to 5)" << endl;
}
void OldMaidUI::invalid() {
    cout << "*********************************************" << endl;
    cout << "The input you have entered is invalid, please try again" << endl;
    cout << "Enter the number followed by the ENTER key" << endl;
}
void OldMaidUI::getReady(int players) {
    cout << "*********************************************" << endl;
    cout << "There will be " << players << " players." << endl;
    cout << "You are Player 1!" << endl;
    cout << "Now shuffling and dealing the cards!" << endl;
    cout << "Press ENTER to continue" << endl;
    std::cin.ignore();
    std::cin.get();
    cout << endl << endl;
}
void OldMaidUI::initPairs() {
    cout << "Now sorting hands and checking for pairs" << endl;
}
void OldMaidUI::startGame(int playerTurn) {
    playerTurn += 1;
    cout << endl << endl;
    cout << "*********************************************" << endl;
    cout << "The game is ready to start!" << endl;
    cout << "At random, player " << playerTurn;
    cout << " gets to start first" << endl;
    cout << "Press ENTER to continue" << endl;
    //std::cin.ignore();
    std::cin.get();
    cout << endl << endl;
}
void OldMaidUI::pTurn(int takeFrom,
                      int takeSize,
                      vector<vector<Cards*> > currentHand) {
    cout << "*********************************************" << endl;
    cout << "It is now your turn!" << endl;
    cout << "You have " << currentHand[0].size() << " cards" << endl;
    cout << "Your current hand is " << endl;
    printHand(currentHand);
    std::cout << "Select a card from Player " << takeFrom+1 << std::endl;
    std::cout << "You may choose a number from 1 to " <<
              takeSize << " ." << std::endl;
}
void OldMaidUI::printHand(vector<vector<Cards*> > currentHand) {
    for (unsigned int i=0; i < currentHand[0].size(); i++) {
        cout << valueToStr(currentHand[0][i]) <<
             " " << suitToStr(currentHand[0][i]);
        cout << endl;
    }
}
void OldMaidUI::pEndTurn(int takeCardFrom,
                         vector<vector<Cards*> > currentHand) {
    cout << "You took a card from Player " << takeCardFrom+1 <<
         " and now have " << currentHand[0].size() <<
         " cards remaining." << endl;
    cout << "Press ENTER to continue" << endl;
    std::cin.ignore();
    std::cin.get();
    cout << endl << endl;
}
void OldMaidUI::aiStartTurn(int playerTurn, int aiHand) {
    cout << "*********************************************" << endl;
    cout << "It is player " << playerTurn+1 << "'s turn." << endl;
    cout << "They currently have " << aiHand << " cards in their hand" << endl;
    cout << "Press ENTER to continue" << endl;
    //std::cin.ignore();
    std::cin.get();
    cout << endl << endl;
}
void OldMaidUI::aiEndTurn(int playerTurn, int takeCardFrom,
                          vector<vector<Cards*> > currentHand) {
    cout << "Player " << playerTurn+1 << " took a card from Player " <<
         takeCardFrom+1 << " and now has " << currentHand[playerTurn].size() <<
         " cards remaining." << endl;
}
void OldMaidUI::discardCheck(Deck *d) {
    cout << "The discard pile is now at: " <<
         d->discardPile.size() << endl;
}
void OldMaidUI::emptyHand() {
    cout << "The other player's hand is empty, no card is selected" << endl;
    cout << "Press ENTER to continue" << endl;
    //std::cin.ignore();
    std::cin.get();
    cout << endl;
}
void OldMaidUI::announcePair() {
    cout << "There is a pair!" << endl;
}

void OldMaidUI::endGame(int loser) {
    if (loser == 0) {
        cout << endl << endl << endl;
        cout << "*********************************************" << endl;
        cout << "=============================================" << endl;
        cout << "The game is over.... you have the remaining " <<
             "Queen and lose the game!!" << endl;
        cout << "Better luck next time!" << endl;
    } else {
        cout << endl << endl << endl;
        cout << "*********************************************" << endl;
        cout << "=============================================" << endl;
        cout << "THE GAME IS OVER!!! Player " << loser+1;
        cout << " has a remaining Queen and loses the game!" << endl;
        cout << "Thank you for playing!" << endl;
    }
}

string OldMaidUI::valueToStr(Cards* currentCard) {
    string valString;
    switch (currentCard->value) {
    case 1:
        valString = "A ";
        break;
    case 10:
        valString = "10 ";
    case 11:
        valString = "J ";
        break;
    case 12:
        valString = "Q ";
        break;
    case 13:
        valString = "K ";
        break;
    default:
        valString = std::to_string(currentCard->value) + " ";
    }
    return valString;
}

string OldMaidUI::suitToStr(Cards* currentCard) {
    string strSuit;
    switch (currentCard->suit) {
    case 0:
        strSuit = "Hearts"; //"\u2665"
        break;
    case 1:
        strSuit = "Spades";
        break;
    case 2:
        strSuit = "Diamonds";
        break;
    case 3:
        strSuit = "Clubs";
        break;
    case 4:
        strSuit = "Nothing";
        break;
    default:
        strSuit = "This didn't work properly";
    }
    return strSuit;
}
