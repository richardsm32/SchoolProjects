#include <gtest/gtest.h>
#include "VillageSquare.h"
#include "Exceptions.h"

TEST(TestVillageSquare, villageSquareLoadLocInfoTest) {
  villageSquare vs;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> This is clearly the central area of the small village. "
            "There are a few townsfolk going about their business "
            "trading and the like. There is a great statue replicating "
            "THE ORB you encountered previously. One man stands out "
            "as being dressed in a more professional manner.\n"
            , vs.loadLocInfo());
}
