#include <gtest/gtest.h>
#include <vector>
#include "GarPostRace.h"
#include "Exceptions.h"

/* Test that outputs the location info for the GarPostRace
to check if it works properly and can only be done if
the constructor works in making the object
*/
TEST(TestGarRace, garPostRaceConstructorTest) {
  garPostRace o;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Congratulations adventurer. You are worthy to have this "
            "phrase to THE ORB. It is \"est\". You may now return "
            "and use the password to complete your quest!\n", o.loadLocInfo());
}
