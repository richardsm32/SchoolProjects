#include <gtest/gtest.h>
#include "IslandOfFools.h"
#include "Exceptions.h"

TEST(TestIslandOfFools, loadLocInfoTest) {
  IslandOfFools iof;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You probably saw this in the menu and thought "
            "it was an interesting place to visit. Sadly you're very wrong."
            " This is a popular battle royale game for "
            "teenagers. It is a terrible and toxic place. The toxicity "
            "acts quickly and you feel all body systems shutting down. "
            "You die a quick and painful death!\n", iof.loadLocInfo());
}
