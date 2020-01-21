#ifndef OLDMAIDUIMOCKTEST_H_INCLUDED
#define OLDMAIDUIMOCKTEST_H_INCLUDED

#include "OldMaidUI.h"
#include <vector>
#include <string>
#include "gmock/gmock.h"

using testing::Return;

class MockOldMaidUI : public OldMaidUI {
 public:
    MockOldMaidUI() {}
    ~MockOldMaidUI() {}

    MOCK_METHOD0(welcome, void());
    MOCK_METHOD0(invalid, void());
    MOCK_METHOD1(getReady, void(int players));
    MOCK_METHOD0(initPairs, void());
    MOCK_METHOD1(startGame, void(int playerTurn));
    MOCK_METHOD3(pTurn, void(int, int, vector<vector<Cards*> >));
    MOCK_METHOD2(pEndTurn, void(int, vector<vector<Cards*> >));
    MOCK_METHOD1(printHand, void(vector<vector<Cards*> >));
    MOCK_METHOD2(aiStartTurn, void(int, int));
    MOCK_METHOD3(aiEndTurn, void(int, int, vector<vector<Cards*> >));
    MOCK_METHOD1(discardCheck, void(Deck*));
    MOCK_METHOD0(emptyHand, void());
    MOCK_METHOD0(announcePair, void());
    MOCK_METHOD1(endGame, void(int));
    MOCK_METHOD1(suitToStr, string(Cards*));
    MOCK_METHOD1(valueToStr, string(Cards*));
};

#endif // OLDMAIDUIMOCKTEST_H_INCLUDED
