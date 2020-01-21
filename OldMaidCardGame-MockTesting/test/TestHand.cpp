#include<gtest/gtest.h>
#include "Deck.h"
#include "Hand.h"
#include "DeckMockTest.h"
#include "HandMockTest.h"
#include <vector>
#include <sstream>
#include <string>

using testing::Return;

TEST(TestHand, initPickPairs_Test) {
    //check the size of the hands vectors before/after pairs
    //deal to 4 players
    Deck d;
    Hand h;
    vector<Cards*> deck;
    vector<vector<Cards*> > hands(4), NoPairs(4);
    deck = d.generateDeck();
    deck = d.shuffleDeck(deck);
    hands = d.Deal(4, deck);
    NoPairs = d.Deal(4, deck);
    hands = h.initPickPairs(4, &d, hands);
    EXPECT_GT(NoPairs[0].size(), hands[0].size());
}

TEST(TestHand, pickCard_Test) {
    //similar setup to above, adds card to hands[0] ...
    //...from hands[players-1]
    //will use players = 4 in this case
    Deck d;
    Hand h;
    vector<Cards*> deck;
    vector<vector<Cards*> > hands(4), NoPairs(4);
    std::istringstream iss("2");
    std::cin.rdbuf(iss.rdbuf());
    int num = 2;
    deck = d.generateDeck();
    hands = d.Deal(4, deck);
    NoPairs = d.Deal(4, deck);
    hands = h.initPickPairs(4, &d, hands);
    hands = h.pickCard(&d, 4, hands);
    while (std::cin >> num) {
        std::cin.clear();
        std::string input;
        std::cin >> input;
        continue;
    }
    //hands = h.pickCard(&d, 4, hands);
    EXPECT_GE(hands[0].size(), hands[3].size());
}

TEST(TestHand, aiPickCard_test) {
    Deck d;
    Hand h;
    vector<Cards*> deck;
    vector<vector<Cards*> > hands(4), NoPairs(4);
    deck = d.generateDeck();
    hands = d.Deal(4, deck);
    NoPairs = d.Deal(4, deck);
    hands = h.initPickPairs(4, &d, hands);
    hands = h.aiPickCard(&d, 4, 1, hands);
    EXPECT_GE(hands[1].size(), hands[0].size());
}
