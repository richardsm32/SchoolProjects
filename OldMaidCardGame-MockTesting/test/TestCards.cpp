#include<gtest/gtest.h>
#include "Cards.h"

TEST(TestCards, constructor_Test) {
    Cards c;
    EXPECT_EQ(0, c.getValue());
}


TEST(TestCards, getValue_Test) {
    Cards c(2, SPADES);
    EXPECT_EQ(2, c.getValue());
}

TEST(TestCards, setValue_Test) {
    Cards c(2, SPADES);
    c.setValue(4);
    EXPECT_EQ(4, c.getValue());
}

TEST(TestCards, getSuit_Test) {
    Cards c(2, SPADES);
    EXPECT_EQ(SPADES, c.getSuit());
}
