#ifndef DECKMOCKTEST_H_INCLUDED
#define DECKMOCKTEST_H_INCLUDED
#include <vector>
#include "gmock/gmock.h"
#include "Deck.h"


using testing::Return;

class MockDeck : public Deck {
 public:
    MockDeck() {}
    ~MockDeck() {}

    MOCK_METHOD2(Deal, vector<vector<Cards*> >
                 (int players, vector<Cards*> shuffledDeck));
    MOCK_METHOD0(generateDeck, vector<Cards*>());
    MOCK_METHOD1(shuffleDeck, vector<Cards*>(vector<Cards*> freshDeck));
};

#endif // DECKMOCKTEST_H_INCLUDED
