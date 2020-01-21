#include <gtest/gtest.h>
#include <vector>
#include "Inventory.h"
#include "Exceptions.h"

TEST(TestInventory, createInventoryTest) {
  Inventory h;
  for (int i = 0; i < 11; i++)
    EXPECT_EQ(0, h.getInven(i));
}


TEST(TestInventory, searchInventoryTest) {
  Inventory h;
  EXPECT_EQ(0, h.searchInventory("hp"));
  EXPECT_EQ(0, h.searchInventory("dice"));
  EXPECT_EQ(0, h.searchInventory("pamph"));
  EXPECT_EQ(0, h.searchInventory("plank"));
  EXPECT_EQ(0, h.searchInventory("twink"));
  EXPECT_EQ(0, h.searchInventory("token"));
  EXPECT_EQ(0, h.searchInventory("tele"));
  EXPECT_EQ(0, h.searchInventory("soto"));
  EXPECT_EQ(0, h.searchInventory("p1"));
  EXPECT_EQ(0, h.searchInventory("p2"));
  EXPECT_EQ(0, h.searchInventory("p3"));
  EXPECT_EQ(0, h.searchInventory("dog"));
}

TEST(TestInventory, throwAddError) {
  Inventory h;
  EXPECT_THROW(h.addItem("asdf"), item_error);
}

TEST(TestInventory, addItemTest) {
  Inventory h;
  h.addItem("pamph");
  EXPECT_EQ(1, h.searchInventory("pamph"));
  h.addItem("p1");
  EXPECT_EQ(1, h.searchInventory("p1"));
  h.addItem("p2");
  EXPECT_EQ(1, h.searchInventory("p2"));
  h.addItem("p3");
  EXPECT_EQ(1, h.searchInventory("p3"));
  h.addItem("hp");
  EXPECT_EQ(1, h.searchInventory("hp"));
  h.addItem("plank");
  EXPECT_EQ(1, h.searchInventory("plank"));
  h.addItem("twink");
  EXPECT_EQ(1, h.searchInventory("twink"));
  h.addItem("token");
  EXPECT_EQ(1, h.searchInventory("token"));
  h.addItem("soto");
  EXPECT_EQ(1, h.searchInventory("soto"));
  h.addItem("tele");
  EXPECT_EQ(1, h.searchInventory("tele"));
  h.addItem("dice");
  EXPECT_EQ(1, h.searchInventory("dice"));
}

TEST(TestInventory, sudItemThrowTest) {
  Inventory h;
  EXPECT_THROW(h.subItem("asdf"), item_error);
}

TEST(TestInventory, subItemTest) {
  Inventory h;
  h.addItem("pamph");
  h.addItem("p1");
  h.addItem("p2");
  h.addItem("p3");
  h.addItem("hp");
  h.addItem("plank");
  h.addItem("twink");
  h.addItem("token");
  h.addItem("soto");
  h.addItem("tele");
  h.addItem("dice");
  h.subItem("pamph");
  EXPECT_EQ(0, h.searchInventory("pamph"));
  h.subItem("p1");
  EXPECT_EQ(0, h.searchInventory("p1"));
  h.subItem("p2");
  EXPECT_EQ(0, h.searchInventory("p2"));
  h.subItem("p3");
  EXPECT_EQ(0, h.searchInventory("p3"));
  h.subItem("hp");
  EXPECT_EQ(0, h.searchInventory("hp"));
  h.subItem("plank");
  EXPECT_EQ(0, h.searchInventory("plank"));
  h.subItem("twink");
  EXPECT_EQ(0, h.searchInventory("twink"));
  h.subItem("token");
  EXPECT_EQ(0, h.searchInventory("token"));
  h.subItem("soto");
  EXPECT_EQ(0, h.searchInventory("soto"));
  h.subItem("tele");
  EXPECT_EQ(0, h.searchInventory("tele"));
  h.subItem("dice");
  EXPECT_EQ(0, h.searchInventory("dice"));
}

TEST(TestInventory, findItemTest) {
  Inventory h;
  EXPECT_EQ("> Health Tonic", h.findItem(0));
  EXPECT_EQ("> Twinkie", h.findItem(4));
  EXPECT_EQ("> Loaded Die", h.findItem(1));
  EXPECT_EQ("> Pamphlet", h.findItem(2));
  EXPECT_EQ("> Nailed Plank", h.findItem(3));
  EXPECT_EQ("> Gold Token", h.findItem(5));
  EXPECT_EQ("> Teleporter", h.findItem(6));
  EXPECT_EQ("> Sword of the ORB", h.findItem(7));
  EXPECT_EQ("> Password 1", h.findItem(8));
  EXPECT_EQ("> Password 2", h.findItem(9));
  EXPECT_EQ("> Password 3", h.findItem(10));
}

TEST(TestInventory, itemIndexError) {
  Inventory h;
  EXPECT_THROW(h.findItem(12), item_error);
  EXPECT_THROW(h.findItem(-12), item_error);
}


TEST(TestInventory, password1ItemTest) {
  Inventory h;
  EXPECT_EQ("> You do not have password 1", h.password1());
  h.addItem("p1");
  EXPECT_EQ("orbis", h.password1());
}


TEST(TestInventory, password2ItemTest) {
  Inventory h;
  EXPECT_EQ("> You do not have password 2", h.password2());
  h.addItem("p2");
  EXPECT_EQ("beatus", h.password2());
}


TEST(TestInventory, password3ItemTest) {
  Inventory h;
  EXPECT_EQ("> You do not have password 3", h.password3());
  h.addItem("p3");
  EXPECT_EQ("est", h.password3());
}

TEST(TestInventory, examinePamphTest) {
  Inventory h;
  EXPECT_EQ("> THE ORB is the greatest thing in all of history."
            " It has been 3007 years since anyone has appeared after visiting "
            "THE ORB. The most supernal goal one can have in life is to return"
            " to THE ORB with an understanding of it's majesty!!! (Written "
            "by GERTRUDE! Contact me for all your HEALTH TONIC needs!!!"
            , h.examinePamph());
}

TEST(TestInventory, examineInvTest) {
  Inventory h;
  EXPECT_EQ("> The Health Tonic seems to be glowing, "
            "making all who see it uneasy.", h.examineInv("hp"));
  EXPECT_EQ("> The Loaded Dice look like a plain old ordinary dice "
            "could be vary useful when gambling.", h.examineInv("dice"));
  EXPECT_EQ("> THE ORB is the greatest thing in all of history."
            " It has been 3007 years since anyone has appeared after visiting "
            "THE ORB. The most supernal goal one can have in life is to return"
            " to THE ORB with an understanding of it's majesty!!! (Written "
            "by GERTRUDE! Contact me for all your HEALTH TONIC needs!!!"
            , h.examineInv("pamph"));
  EXPECT_EQ("> The nailed plank looks like something out of the "
            "Walking Dead. Could be useful in a fight.", h.examineInv("plank"));
  EXPECT_EQ("> It's a twinkie, it looks delicious but you are "
            "gluten intolerant!",
            h.examineInv("twink"));
  EXPECT_EQ("> The Gold Token looks like an ancient relic but really "
            "it is just a gold chocolate coin.", h.examineInv("token"));
  EXPECT_EQ("> The outside of the teleporter looks plain with a "
            "few dials on it controlling the locations.", h.examineInv("tele"));
  EXPECT_EQ("> I don't know how you figured this one out, it is "
            "NOT IN THE DAMN GAME. FRICK!!!!!!!!!!!", h.examineInv("soto"));
  EXPECT_EQ("> Password 1 is: \"orbis\"", h.examineInv("p1"));
  EXPECT_EQ("> Password 2 is: \"beatus\"", h.examineInv("p2"));
  EXPECT_EQ("> Password 3 is: \"est\"", h.examineInv("p3"));
  EXPECT_EQ("> You don't have an item by that name, try examining again"
            , h.examineInv("asdf"));
}
