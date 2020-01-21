#include <gtest/gtest.h>
#include "EdgeVillage.h"
#include "Exceptions.h"

TEST(TestEdgeVillage, edgeVillageLoadLocInfoTest) {
  edgeVillage ev;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You are thrown into some shrubbery on the edge of a "
            "medieval-looking village. You land on an old backpack, and "
            "decide it's a good idea to put it on. "
            "Then a crazed woman rushes over to meet you.\n"
            , ev.loadLocInfo());
}
