#include <gtest/gtest.h>
#include "SuperMarket.h"
#include "Exceptions.h"

TEST(TestSuperMarker, superMarketLoadLocInfoTest) {
  superMarket sm;
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> After winding through the alleyway you find the back "
            "entrance to an abandoned grocery store. It has been heavily "
            "looted but there are some supplies left. You see some "
            "compelling propaganda brochures and some unhealthy "
            "food items.\n", sm.loadLocInfo());
}
