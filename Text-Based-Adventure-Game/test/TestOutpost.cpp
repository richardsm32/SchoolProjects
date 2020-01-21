#include <gtest/gtest.h>
#include "Outpost.h"
#include "Exceptions.h"

TEST(TestOutpost, outpostLoadLocInfoTest) {
  outpost o;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You venture to a re-purposed factory a short distance "
            "away. You are met by guards almost as soon as the "
            "factory is in sight. You explain to them you seek "
            "to return to THE ORB. This seems to please them and "
            "they are less hostile towards you. They take you "
            "to the leader.\n", o.loadLocInfo());
}
