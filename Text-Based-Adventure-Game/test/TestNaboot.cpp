#include <gtest/gtest.h>
#include "Naboot.h"
#include "Exceptions.h"

TEST(TestNaboot, nabootLoadLocInfoTest) {
  naboot n;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You arrive on a paved area at the edge of a swamp. "
            "From the look of the far away buildings this is clearly "
            "a futuristic game where technology is "
            "far advanced compared to what you’ve seen thus far. "
            "A strange amphibious character is at a booth on the "
            "edge of the swamp.\n", n.loadLocInfo());
}
