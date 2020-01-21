#include <gtest/gtest.h>
#include "Tavern.h"
#include "Exceptions.h"

TEST(TestTavern, tavernLoadLocInfoTest) {
  Tavern t;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> The tavern is known as \"The Prancing Floutist\". "
            "Inside there are only a few people. The bartender, "
            "a gambler tucked away in a corner, and the namesake "
            "of the place - a floutist performing ballads whilst "
            "dancing around the establishment.\n", t.loadLocInfo());
}
