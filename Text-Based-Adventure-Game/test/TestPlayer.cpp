#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Exceptions.h"

TEST(TestPlayer, playerConstructorTest) {
  Player g;
  EXPECT_EQ(1, g.getPlayerAlive());
}

TEST(TestPlayer, playerGetSetName) {
  Player g;
  g.setName("Tim the Tat Man");
  EXPECT_EQ("Tim the Tat Man", g.getName());
}

TEST(TestPlayer, playerGetSetPlayerAlive) {
  Player g;
  g.setPlayerAlive(0);
  EXPECT_EQ(0, g.getPlayerAlive());
  g.setPlayerAlive(1);
  EXPECT_EQ(1, g.getPlayerAlive());
}

TEST(TestPlayer, playerGiveTest) {
  Player g;
  g.playerGet("hp");
  EXPECT_EQ(1, g.searchPlayerInv("hp"));
  g.playerGive("hp");
  EXPECT_EQ(0, g.searchPlayerInv("hp"));
}

TEST(TestPlayer, searchPlayerInvTest) {
  Player g;
  g.playerGet("hp");
  EXPECT_EQ(1, g.searchPlayerInv("hp"));
  g.playerGet("token");
  EXPECT_EQ(1, g.searchPlayerInv("token"));
}

TEST(TestPlayer, playerGetTest) {
  Player g;
  g.playerGet("token");
  EXPECT_EQ(1, g.searchPlayerInv("token"));
  g.playerGet("soto");
  EXPECT_EQ(1, g.searchPlayerInv("soto"));
}

TEST(TestPlayer, playerTravelTest) {
  Player g;
  EXPECT_EQ(1, g.getPlayerLocation());
  g.playerTravel(g);
  EXPECT_EQ(2, g.getPlayerLocation());
  g.playerTravel(g);
  g.playerTravel(g);
  g.playerTravel(g);
  EXPECT_EQ(4, g.getPlayerLocation());
  g.setPlayerLocation(7, g);
  g.playerTravel(g);
  g.playerTravel(g);
  EXPECT_EQ(8, g.getPlayerLocation());
}


TEST(TestPlayer, playerGetSetLocation1Test) {
  Player g;
  g.setPlayerLocation(1, g);
  EXPECT_EQ(1, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
  "**********************************************\n"
  "> You are thrown into some shrubbery on the edge of a "
  "medieval-looking village. You land on an old backpack, and "
  "decide it's a good idea to put it on. "
  "Then a crazed woman rushes over to meet you.\n"
            , g.setPlayerLocation(1, g));
}

TEST(TestPlayer, playerGetSetLocation2Test) {
  Player g;
  g.setPlayerLocation(2, g);
  EXPECT_EQ(2, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> The tavern is known as \"The Prancing Floutist\". "
            "Inside there are only a few people. The bartender, "
            "a gambler tucked away in a corner, and the namesake "
            "of the place - a floutist performing ballads whilst "
            "dancing around the establishment.\n"
            , g.setPlayerLocation(2, g));
}

TEST(TestPlayer, playerGetSetLocation3Test) {
  Player g;
  g.setPlayerLocation(3, g);
  EXPECT_EQ(3, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> This is clearly the central area of the small village. "
            "There are a few townsfolk going about their business "
            "trading and the like. There is a great statue replicating "
            "THE ORB you encountered previously. One man stands out "
            "as being dressed in a more professional manner.\n"
            , g.setPlayerLocation(3, g));
}

TEST(TestPlayer, playerGetSetLocation4Test) {
  Player g;
  g.setPlayerLocation(4, g);
  EXPECT_EQ(4, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> This section of the village houses the poor and outcast. "
            "It is not well kept and there is refuse among the few "
            "small shacks. One shack has all sorts of ORB "
            "paraphernalia posted on the exterior. There is a "
            "gaping hole in the wall under a walkway.\n"
            , g.setPlayerLocation(4, g));
}

TEST(TestPlayer, playerGetSetLocation5Test) {
  Player g;
  g.setPlayerLocation(5, g);
  EXPECT_EQ(5, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> The rush of transport leaves you feeling disoriented "
            "and groggy. As you start to come to your senses you "
            "realize there is imminent danger. You are in a "
            "ruined city, with a dangerous looking mercenary "
            "in the distance quickly moving in. You see a nailed "
            "plank nearby and quickly pick it up in preparation for a fight!\n"
            , g.setPlayerLocation(5, g));
}

TEST(TestPlayer, playerGetSetLocation6Test) {
  Player g;
  g.setPlayerLocation(6, g);
  EXPECT_EQ(6, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> After winding through the alleyway you find the back "
            "entrance to an abandoned grocery store. It has been heavily "
            "looted but there are some supplies left. You see some "
            "compelling propaganda brochures and some unhealthy "
            "food items.\n"
            , g.setPlayerLocation(6, g));
}

TEST(TestPlayer, playerGetSetLocation7Test) {
  Player g;
  g.setPlayerLocation(7, g);
  EXPECT_EQ(7, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You venture to a re-purposed factory a short distance "
            "away. You are met by guards almost as soon as the "
            "factory is in sight. You explain to them you seek "
            "to return to THE ORB. This seems to please them and "
            "they are less hostile towards you. They take you "
            "to the leader.\n"
            , g.setPlayerLocation(7, g));
}

TEST(TestPlayer, playerGetSetLocation8Test) {
  Player g;
  g.setPlayerLocation(8, g);
  EXPECT_EQ(8, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> As discreetly as possible you move to the edge of the city."
            " You hear an enemy envoy approach your position and "
            "quickly hide! Suddenly their vehicle is fired at by an "
            "rpg and they are blown to bits. A man dressed like a warrior "
            "cowboy steps out from a concealed turret.\n"
            , g.setPlayerLocation(8, g));
}

TEST(TestPlayer, playerGetSetLocation9Test) {
  Player g;
  g.setPlayerLocation(9, g);
  EXPECT_EQ(9, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You arrive on a paved area at the edge of a swamp. "
            "From the look of the far away buildings this is clearly "
            "a futuristic game where technology is "
            "far advanced compared to what you’ve seen thus far. "
            "A strange amphibious character is at a booth on the "
            "edge of the swamp.\n"
            , g.setPlayerLocation(9, g));
}

TEST(TestPlayer, playerGetSetLocation10Test) {
  Player g;
  g.setPlayerLocation(10, g);
  EXPECT_EQ(10, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Thankfully the previous adventurer had the game containing "
            "Java programmed into the teleporter and you appear in the "
            "city square just outside his headquarters. There is nothing "
            "interest other than the entrance to the HQ.\n"
            , g.setPlayerLocation(10, g));
}

TEST(TestPlayer, playerGetSetLocation11Test) {
  Player g;
  g.setPlayerLocation(11, g);
  EXPECT_EQ(11, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> Again the location for the exact base you need was pre-"
            "programmed into the teleporter. Hothe is a freezing cold "
            "planet and you are not dressed for the weather. Best to "
            "find Ackbari quickly and get to business.\n"
            , g.setPlayerLocation(11, g));
}

TEST(TestPlayer, playerGetSetLocation12Test) {
  Player g;
  g.setPlayerLocation(12, g);
  EXPECT_EQ(12, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> The atmosphere in this game is bright and sunny, yet "
            "something feels very wrong. If you look too far off the "
            "racetrack there are many crashed go-karts and the remains"
            " of the poor souls that piloted them. Garfield, the final"
            " guardian of THE ORB clearly takes this role seriously."
            " The only option is to approach him and race for the "
            "final phrase and access to THE ORB.\n"
            , g.setPlayerLocation(12, g));
}

/* Test requires interaction
TEST(TestPlayer, playerGetSetLocation13Test) {
Player g;
g.setPlayerLocation(13, g);
EXPECT_EQ(13, g.getPlayerLocation());
*/

TEST(TestPlayer, playerGetSetLocation14Test) {
  Player g;
  g.setPlayerLocation(14, g);
  EXPECT_EQ(14, g.getPlayerLocation());
  EXPECT_EQ("\n\n"
            "**********************************************\n"
            "> You probably saw this in the menu and thought "
            "it was an interesting place to visit. Sadly you're very wrong."
            " This is a popular battle royale game for "
            "teenagers. It is a terrible and toxic place. The toxicity "
            "acts quickly and you feel all body systems shutting down. "
            "You die a quick and painful death!\n"
            , g.setPlayerLocation(14, g));
}


//This test will cout info
TEST(TestPlayer, playerHelpTest) {
  Player g;
  EXPECT_EQ("> Welcome to the help tab: \n"
            ">> Your list of action are as follows.\n"
            "1) use\n"
            "2) examine\n"
            "3) travel\n"
            "4) talk\n"
            "5) help\n"
            "6) save\n"
            "7) load\n"
            "> Please enter the action as they appeared, "
            "in lowercase and with correct spelling\n"
            "> For items enter the following codes: \n"
            "- hp for Health Tonic\n"
            "- dice for Loaded Dice\n"
            "- pamph for Pamphlet\n"
            "- plank for Nailed Plank\n"
            "- twink for Twinkie\n"
            "- token for Gold Token\n"
            "- tele for Teleporter\n"
            "To quit the game at any time use ctrl + c.\n",
            g.playerHelp());
}

/*
TEST(TestPlayer, playerUseTest) {
  Player g;
  std::cout << std::endl;
  std::cout << "Just hit enter then type \"no\"" << std::endl;
  g.playerUse(g);
   Should Print
  > That is and invalid item or you do not have "
  "it in your inventory. Enter yes to try again "
  "anything else to exit use item"

  g.playerGet("hp");
  std::cout << std::endl;
  std::cout << "ENTER \"hp\"" << std::endl;
  g.playerUse(g);
   Should Print
  "> Why would you drink something Gertrude gave you? "
     "Do you have a death wish? Well, wish granted! YOU ARE DEAD!"

  EXPECT_EQ(0, g.getPlayerAlive());
  g.playerGet("dice");
  std::cout << std::endl;
  std::cout << "ENTER \"dice\"" << std::endl;
  g.playerUse(g);
   Should Print

} */

TEST(TestPlayer, numberToLocationTest) {
  Player g;
  EXPECT_EQ("> Edge of Village", g.numberToLocation(1));
  EXPECT_EQ("> Tavern", g.numberToLocation(2));
  EXPECT_EQ("> Village Square", g.numberToLocation(3));
  EXPECT_EQ("> Slums", g.numberToLocation(4));
  EXPECT_EQ("> Inner City", g.numberToLocation(5));
  EXPECT_EQ("> Supermarket", g.numberToLocation(6));
  EXPECT_EQ("> Outpost", g.numberToLocation(7));
  EXPECT_EQ("> Outer City", g.numberToLocation(8));
  EXPECT_EQ("> Naboot", g.numberToLocation(9));
  EXPECT_EQ("> Tatooined", g.numberToLocation(10));
  EXPECT_EQ("> Hothe", g.numberToLocation(11));
  EXPECT_EQ("> Garfields Lair", g.numberToLocation(12));
  EXPECT_EQ("> The Orb", g.numberToLocation(13));
  EXPECT_EQ("> Island of Fools", g.numberToLocation(14));
}

TEST(TestPlayer, numberToLocationInvalidInputTest) {
  Player g;
  EXPECT_EQ("> That is not a valid location id"
            , g.numberToLocation(30));
  EXPECT_EQ("> That is not a valid location id"
            , g.numberToLocation(-30));
}

TEST(TestPlayer, testPlayerAction) {
  Player g;
  /*should print
  "> That action does not exist!"
  " Please choose another action."
  */
  g.playerAction("asdf", g);
}

/*
Test requires user input
TEST(TestPlayer, changePChoiceTest) {
  Player g;
  g.changePChoice();
}

Test requires user input
TEST(TestPlayer, playerTeleTest) {
  Player g;
  g.playerTele(g);
}
*/

TEST(TestPlayer, examineRoom4Test) {
  Player g;
  g.setPlayerLocation(4, g);
  EXPECT_EQ("> You see a hole in the wall of a shack, and as you look "
            "inside you are mauled by hundreds of rats and eaten alive!!",
            g.examineRoom(g));
}

TEST(TestPlayer, examineRoom3Test) {
  Player g;
  g.setPlayerLocation(3, g);
  EXPECT_EQ("> As you examine the statue, the statue says: This monument "
           "was erected in the Year of Our ORB 7412, to THE perfect all "
           "knowing ORB.",
           g.examineRoom(g));
}

TEST(TestPlayer, examineRoom6Test) {
  Player g;
  g.setPlayerLocation(6, g);
  EXPECT_EQ("> You see some twinkies on the ground so you pick one up and "
           "put it in your inventory.",
           g.examineRoom(g));
}

TEST(TestPlayer, examineRoomOtherTest) {
  Player g;
  g.setPlayerLocation(10, g);
  EXPECT_EQ("> There is nothing of interest in this location.",
           g.examineRoom(g));
}

TEST(TestPlayer, getrankTestTest) {
  Player g;
  EXPECT_EQ(0, g.getRancorTest());
}

TEST(TestPlayer, setrankTestTest) {
  Player g;
  g.setRancorTest(1);
  EXPECT_EQ(1, g.getRancorTest());
}

TEST(TestPlayer, playerTalk5Test) {
  Player g;
  g.setPlayerLocation(5, g);
  // should print
  // "> You just killed the only person you could talk to."
  g.playerTalk(g);
}

TEST(TestPlayer, playerTalk6Test) {
  Player g;
  g.setPlayerLocation(6, g);
  // should print
  // "> You are in an abandoned super market, "
  // "there is no-one around to talk to."
  g.playerTalk(g);
}
