#include <gtest/gtest.h>
#include "GarRace.h"
#include "Exceptions.h"

/* Test that outputs the location info for the garRace
to check if it works properly and can only be done if
the constructor works in making the object
*/
TEST(TestGarRace, garRaceConstructorTest) {
  garRace o;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Mwahahaha, you actually wanted to race."
            " Get ready to be destroyed.\n", o.loadLocInfo());
}
