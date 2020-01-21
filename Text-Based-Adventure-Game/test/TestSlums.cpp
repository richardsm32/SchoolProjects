#include <gtest/gtest.h>
#include "Slums.h"
#include "Exceptions.h"

TEST(TestSlums, slumsLoadLocInfoTest) {
  Slums s;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> This section of the village houses the poor and outcast. "
            "It is not well kept and there is refuse among the few "
            "small shacks. One shack has all sorts of ORB "
            "paraphernalia posted on the exterior. There is a "
            "gaping hole in the wall under a walkway.\n", s.loadLocInfo());
}
