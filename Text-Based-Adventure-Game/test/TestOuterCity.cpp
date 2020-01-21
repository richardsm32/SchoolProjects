#include <gtest/gtest.h>
#include "OuterCity.h"
#include "Exceptions.h"

TEST(TestOuterCity, outerCityLoadLocInfoTest) {
  outerCity oc;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> As discreetly as possible you move to the edge of the city."
            " You hear an enemy envoy approach your position and "
            "quickly hide! Suddenly their vehicle is fired at by an "
            "rpg and they are blown to bits. A man dressed like a warrior "
            "cowboy steps out from a concealed turret.\n", oc.loadLocInfo());
}
