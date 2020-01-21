#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "OldMaid.h"
#include "OldMaidUI.h"
#include "DeckMockTest.h"
#include "HandMockTest.h"
#include "OldMaidUIMockTest.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using testing::_;
using testing::Return;

TEST(TestOldMaid, game_Test) {
    MockOldMaidUI u;
    MockHand h;
    MockDeck d;
    OldMaid o;
    vector<Cards*> mdeck(1);
    vector<vector<Cards*> > mhands(4);

    /*EXPECT_CALL(u, getReady(_))
    .Times(1);*/

    EXPECT_CALL(d, generateDeck())
    .Times(1)
    .WillOnce(Return(mdeck));

    EXPECT_CALL(d, shuffleDeck(mdeck))
    .Times(1)
    .WillOnce(Return(mdeck));

    EXPECT_CALL(d, Deal(_, mdeck))
    .Times(1)
    .WillOnce(Return(mhands));

    /*EXPECT_CALL(u, initPairs())
    .Times(1)
    .WillOnce(Return());*/

    EXPECT_CALL(h, initPickPairs(_, &d, mhands))
    .Times(1)
    .WillOnce(Return(mhands));


    EXPECT_EQ(0, o.game(4, 0, &u, &d, &h));
}

TEST(TestOldMaid, numberOfPlayers_Test) {
    OldMaidUI u;
    //numberOfPlayers(u)
}

TEST(TestOldMaid, sumSize_Test) {
    Cards* c;
    Deck d;
    Hand h;
    OldMaid o;
    vector<Cards*> deck;
    vector<vector<Cards*> > hands(4), onlyOne(1);
    onlyOne[0].push_back(c);
    deck = d.generateDeck();
    //deal into 4 hands
    hands = d.Deal(4, deck);
    //sumSize returns true when 1 card is left
    EXPECT_FALSE(o.sumSize(4, hands));
    EXPECT_TRUE(o.sumSize(1, onlyOne));
}
