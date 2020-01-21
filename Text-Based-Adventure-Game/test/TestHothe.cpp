#include <gtest/gtest.h>
#include "Hothe.h"
#include "Exceptions.h"

TEST(TestHothe, hotheLoadLocInfoTest) {
  hothe h;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Again the location for the exact base you need was pre-"
            "programmed into the teleporter. Hothe is a freezing cold "
            "planet and you are not dressed for the weather. Best to "
            "find Ackbari quickly and get to business.\n", h.loadLocInfo());
}
