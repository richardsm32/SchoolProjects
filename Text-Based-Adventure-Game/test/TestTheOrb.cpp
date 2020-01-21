#include <gtest/gtest.h>
#include "TheOrb.h"
#include "Exceptions.h"

/* Test that outputs the location info for the orb
to check if it works properly and can only be done if
the constructor works in making the object
*/
TEST(TestInnerCity, innercityConstructorTest) {
  TheOrb o;
  EXPECT_EQ("\n\n"
            "> You are a lowly maintenance sprite from a small "
            "video game arcade (kind of like Wreck-It-Ralph). "
            "When the user is "
            "playing your game it is go-time! You have to make sure the "
            "information flows freely and their experience is perfect. "
            "However when the system isn't in use you have some free time "
            "to explore. After following some obscure data tunnels, you "
            "find an area you've never been to before. Beyond the "
            "threshold of a doorway you see a pulsing blue light and "
            "move towards it. As soon as you enter the room, the doorway "
            "seals! You are trapped in a small room with a pulsing blue "
            "orb.\n", o.loadLocInfo());
}

/*
is an interaction with player
TEST(TestTheOrb, theOrbGazeTest) {
  TheOrb o;
  o.gazeOrb();
}
*/

/*
test requires interaction with player
TEST(TestTheOrb, enterPassTest) {
  TheOrb o;
  o.enterPass();
}
*/
