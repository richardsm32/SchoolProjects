#ifndef HANDMOCKTEST_H_INCLUDED
#define HANDMOCKTEST_H_INCLUDED
#include <vector>
#include "gmock/gmock.h"
#include "Hand.h"

using testing::Return;

class MockHand : public Hand {
 public:
    MockHand() {}
    ~MockHand() {}

    MOCK_METHOD3(initPickPairs, vector<vector<Cards*> >(
                                        int player,
                                        Deck *d,
                                        vector<vector<Cards*> > freshHands));
    MOCK_METHOD3(pickCard, vector<vector<Cards*> >(
                                        Deck *d,
                                        int players,
                                        vector<vector<Cards*> > playerHands));
    MOCK_METHOD4(aiPickCard, vector<vector<Cards*> >(
                                        Deck *d,
                                        int players,
                                        int playerTurn,
                                        vector<vector<Cards*> > playerHands));
};
#endif // HANDMOCKTEST_H_INCLUDED
