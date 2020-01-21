#include <gtest/gtest.h>
#include "GarfieldsLair.h"
#include "Exceptions.h"

TEST(TestGarfieldsLair, garfieldLairLoadLocInfoTest) {
  garfieldsLair gl;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> The atmosphere in this game is bright and sunny, yet "
            "something feels very wrong. If you look too far off the "
            "racetrack there are many crashed go-karts and the remains"
            " of the poor souls that piloted them. Garfield, the final"
            " guardian of THE ORB clearly takes this role seriously."
            " The only option is to approach him and race for the "
            "final phrase and access to THE ORB.\n", gl.loadLocInfo());
}
