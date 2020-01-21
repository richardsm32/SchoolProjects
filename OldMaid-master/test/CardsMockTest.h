#ifndef CARDSMOCKTEST_H_INCLUDED
#define CARDSMOCKTEST_H_INCLUDED

#include "gmock/gmock.h"
#include "Cards.h"

using testing::Return;

class MockCards : public Cards {
 public:
    MockCards() {}
    ~MockCards() {}

    MOCK_METHOD0(getValue, int());
    MOCK_METHOD1(setValue, void(int a));
    MOCK_METHOD0(getSuit, Suit());
};

#endif // CARDSMOCKTEST_H_INCLUDED
