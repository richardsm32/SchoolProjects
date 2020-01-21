#include<gtest/gtest.h>
#include "Deck.h"
#include "Cards.h"
#include <vector>


TEST(TestDeck, generateDeck_Test) {
    Deck d;
    Cards* a;
    //resulting deck is 51 because the Queen is removed
    vector<Cards*> c(51, a), deck;
    deck = d.generateDeck();
    EXPECT_EQ(deck.size(), c.size());
}

TEST(TestDeck, shuffleDeck_Test) {
    Deck d;
    vector<Cards*> c, notShuffled;
    c = d.generateDeck();
    notShuffled = d.generateDeck();
    c = d.shuffleDeck(c);
    //using built-in shuffle func.
    //Ace of Hearts will be first card
    bool shuffled = true;
    if (c[0]->getValue() == 1 && c[13]->getValue() == 1
        && c[26]->getValue() == 1)
            shuffled = false;
    EXPECT_TRUE(shuffled);
}

TEST(TestDeck, Deal_Test) {
    Deck d;
    vector<Cards*> c, e;
    vector<vector<Cards*> > f;
    //deal out c, check size vs e
    c = d.generateDeck();
    e = d.generateDeck();
    f = d.Deal(4, c);
    EXPECT_NE(c.size(), f[0].size());
}
