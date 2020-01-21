#include <gtest/gtest.h>
#include "Tatooined.h"
#include "Exceptions.h"

TEST(TestTatooined, tatooinedLoadLocInfoTest) {
  tatooined t;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Thankfully the previous adventurer had the game containing "
            "Java programmed into the teleporter and you appear in the "
            "city square just outside his headquarters. There is nothing "
            "interest other than the entrance to the HQ.\n", t.loadLocInfo());
}
