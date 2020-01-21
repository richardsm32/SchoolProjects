#include <gtest/gtest.h>
#include "Game.h"
#include "Exceptions.h"

TEST(TestGame, gameConstructorTest) {
  Game g;
  EXPECT_EQ(true, g.getGameRun());
}

TEST(TestGame, gameGetGameRunTest) {
  Game g;
  EXPECT_EQ(true, g.getGameRun());
}
