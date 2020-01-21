/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Implements the NPC talking lines and statements.
* Calls other functions as needed to progress the game.
* (i.e. adding an item to inventory during conversation, etc.)
*/

#include "Npc.h"
#include <unistd.h>
#include "Exceptions.h"
#include "DicePuzzle.h"
#include "GarRace.h"
#include "GarPostRace.h"
#include "RacingPuzzle.h"
#include "CombatPuzzle.h"
#include <string>
#include <iostream>
using std::string;


Npc::Npc() {}

int Npc::changeChoice() {
  string var;
  getline(std::cin, var);
  try {
    int c = stoi(var);
    return c;
  } catch (const std::invalid_argument& e) {
    return -1;
  }
}

void Npc::Gertrude(Player& p) {
  int select0;
  std::cout << "> Crazy lady: Have you just come from THE ORB?!?! I told them"
            << " it was real! I knew it!! I too have been to THE ORB. "
            << "Many ages ago! Now I remain here so I can GET BACK!! "
            << "You must return to THE ORB!! "
            << "You must get back there!!! " << std::endl;
  do {
    std::cout << "1. Okay...." << std::endl;
    std::cout << "2. Well I'll be going now..." << std::endl;
    std::cout << "> Choose (enter a number on the keyboard)" << std::endl;
    select0 = changeChoice();
    std::cout << std::endl;
  } while (select0 == -1);
  switch (select0) {
  case 1 : {
    int select1;
    std::cout << "> Gertrude: I, Gertrude, will help you return to THE ORB! "
              << "You can stay here with me and return the next "
              << "time someone comes through. It only took 3007 "
              << "years for someone to come through! I sell "
              << "health tonics to passersby in the meantime. "
              << "Here - you can have one FOR FREE! "
              << "Then it’s only $34.99 each lunar cycle for 12 more! "
              << "You can even sell them with ME! I get a 2.5% cut "
              << "of you sales, then Chaz gets a cut of that "
              << "because he sold them to me, then if you sign "
              << "someone else up you get a cut of their sales, "
              << "then if they sign someone ….. "
              << "(this goes on for a while)" << std::endl;
    do {
      std::cout << "1. Sure I'll take one, just leave me alone" << std::endl;
      std::cout << "2. Quickly move to Tavern" << std::endl;
      std::cout << "3. Quickly move to Village Square" << std::endl;
      std::cout << "4. Stay and sell tonics" << std::endl;
      std::cout << "> Choose" << std::endl;
      std::cout << "<< ";
      select1 = changeChoice();
    } while (select1 == -1);
    switch (select1) {
    case 1:
      std::cout << "> (You take the health tonic and move away from Gertrude)"
                << std::endl;
      p.playerGet("hp");
      return;
    case 2:
      std::cout << p.setPlayerLocation(2, p) << std::endl;
      return;
    case 3:
      std::cout << p.setPlayerLocation(3, p) << std::endl;
      return;
    case 4: {
      std::cout << "> (You last only a few days, suffering greatly by "
                << "listening to Gertrude all day, then dying "
                << "of poverty and starvation)" << std::endl;
      p.setPlayerAlive(0);
      return;
    }
    }
    case 2:
      std::cout << p.setPlayerLocation(1, p) << std::endl;
      return;

    default:
      std::cout << "> You have chosen poorly, try again";
      Gertrude(p);
    }
  }
}

void Npc::Bartender() {
  int select0;
  std::cout << "> Bartender: Oy there foreigner, you're not from around "
            << "here are you? " << std::endl;
  do {
    std::cout << "1. Order a drink" << std::endl;
    std::cout << "2. Ask about the village" << std::endl;
    std::cout << "> Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> Bartender: This is a delicious concoction we call "
              << "Orb Beer" << std::endl;
    sleep(1);
    std::cout << "(It tastes terrible)" << std::endl;
    return;
  case 2:
    std::cout << "> Bartender: There’s some crazies around here - "
              << "all b’cause of THE ORB"
              << ". Gertrude thinks she’s been there. Edmund the Bastard "
              << "thinks he’s got a way to get to a new dimension. Simon"
              << " over there spends his entire days in me tavern. Claims "
              << "he has insider knowledge of THE ORB, "
              << "but only those \"learned\""
              << " in the ways of THE ORB can learn it." << std::endl;
    return;
  }
}

void Npc::Simon(Player& p) {
  int gameresult = 0;
  std::cout << "> Simon: Hello friend. You are on a quest. I have great "
            << "knowledge "
            << "that will aid you, but you must prove yourself worthy. "
            << "You must test the die of THE ORB. Roll the sacred numbers "
            << "of THE ORB and I will share great knowledge. " << std::endl;
  // Call to DiceTest, return a 1 or 0 (pass/fail) from RNG.
  // loadedDie can automatically cause a pass
  if (p.searchPlayerInv("dice") == 1) {
    gameresult = 1;
  } else {
    DicePuzzle dicep;
    gameresult = dicep.playPuzzle();
  }
  if (gameresult == 1) {
    std::cout << "> You roll your loaded dice and the dice land";
    std::cout << " 6, 7, 2." << std::endl;
    std::cout << "> Well done traveler. The first phrase of the great ";
    std::cout << "password is \"beatus\", keep this knowledge and be well"
              << std::endl;
    std::cout << "> (Simon has given you a small piece of "
              << "parchment containing this phrase" << std::endl;
    p.playerGet("p1");
  } else if (gameresult == 0) {
    std::cout << "> You must gain greater favour of THE ORB to pass my test!!"
              << std::endl;
  } else {
    std::cout << "> Shouldn't get here..." << std::endl;
  }
}

void Npc::Roy(Player& p) {
  int select0;
  std::cout << "> Sharply Dressed Man: Welcome to Roysville. I am Roy ORBison"
            << ", the founder of this"
            << " village. You seem to be a traveller from foreign lands, what"
            << " brings you to our village? " << std::endl;
  do {
    std::cout << "1. Not really sure " << std::endl;
    std::cout << "2. I seek THE ORB?" << std::endl;
    std::cout << "Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> Roy: Well alright then, enjoy your visit!" << std::endl;
    return;
  case 2:
    std::cout << "> Roy: You must have encountered Gertrude. "
              << "There may be truth "
              << "to what she says, but beware her tonics. They are terrible"
              << ". Also don’t buy in to her tonic sales. Terrible financial"
              << " decision. I know from experience. " << std::endl;
    std::cout << "> There is a man in the slums. The Bastard, Edmund "
              <<  "we call him. He claims to know how to travel towards "
              << "THE ORB. Though he may just be a craved lunatic."
              << " You may want to look at this pamphlet "
              << "for more info" << std::endl;
    p.playerGet("pamph");
    std::cout << "> (He gives you a pamphlet with information about "
              << "THE ORB.)" << std::endl;
  }
}

void Npc::Edmund(Player & p) {
  int select0;
  string answer1, answer2;
  std::cout << "> You knock at the door and the door swings open with a "
            << "loud \"HELLO!\"" << std::endl << "I AM EDMUND THE BASTARD. "
            << "YOU ARE THE SEEKER OF THE ORB YES?" << std::endl;
  do {
    std::cout << "1. No" << std::endl << "2. Yes" << std::endl;
    std::cout << "Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> Edmund: WELL THEN GO AWAY!" << std::endl;
    return;
  // exit
  case 2:  // 3 questions
    std::cout << "> Edmund: ANSWER ME THESE QUESTIONS THREE! " << std::endl;
    // player response??
    std::cout << "> Q1 - IN WHICH YEAR OF OUR ORB WAS THE STATUE IN ";
    std::cout << "VILLAGE SQUARE CONSTRUCTED? " << std::endl;
    std::cout << "> (You must enter the exact year)" << std::endl;
    std::cout << "<< ";
    getline(std::cin, answer1);
    if (answer1 == "7412") {
      std::cout << "> CORRECT." << std::endl;
      std::cout << "> Q2 - HOW MANY YEARS HAS IT BEEN SINCE A TRAVELLER "
                << "APPEARED ON THE EDGE OF THE VILLAGE AFTER VIEWING THE "
                << "ORB? (Again, enter the exact number of years)" << std::endl;
      std::cout << "<< ";
      getline(std::cin, answer2);
      if (answer2 == "3007") {
        int select1;
        std::cout << "> CORRECT." << std::endl;
        std::cout << "> Q3 - WHAT ARE THE SACRED NUMBERS OF THE ORB? "
                  << std::endl;
        do {
          std::cout << "1. I don’t know yet…" << std::endl;
          std::cout << "2. 37, 4, 18" << std::endl;
          std::cout << "Choose" << std::endl;
          std::cout << "<< ";
          select1 = changeChoice();
        } while (select1 == -1);
        switch (select1) {
        case 1: {
          std::cout << "> Edmund: WELL THAT’S SLOPPY DESIGN TO ASK A "
                    << "QUESTION WHEN "
                    << "THE ANSWER HASN’T BEEN EXPLAINED YET. YOU WILL "
                    << "NEED TO REMEMBER 6, 7, AND 2!!" << std::endl;
          std::cout << "> CONTINUE ON YOUR QUEST! "
                    << "BEST OF LUCK!" << std::endl;
          std::cout << "> (Edmund points a device at you, which at first "
                    << "glance appears to be a taser. Thankfully you don’t "
                    << "feel jolts of electricity but the sudden rush like "
                    << "before. You feel as if thrown through "
                    << "space and time." << std::endl;
          sleep(1);
          std::cout << p.setPlayerLocation(5, p) << std::endl;
          CombatPuzzle cp;
          cp.Combat(p);
          p.playerGet("plank");
          return;
        }
        case 2:  //wrong answer for q3
          std::cout << "> Edmund: Slanderer of THE ORB!" << std::endl;
          std::cout << "> Edmund pulls a sword from ";
          std::cout << "a scabbard and decapitates you " << std::endl;
          p.setPlayerAlive(0);
          return;
        }
      } else {
        std::cout << "> INCORRECT! STUDY AND TRY AGAIN!" << std::endl;
      }
    } else {
      std::cout << "> INCORRECT! STUDY AND TRY AGAIN!" << std::endl;
    }
  }
}

void Npc::OutpostLeader(Player& p) {
  int select0, select1;
  std::cout << "> Leader: Hello, traveler of THE ORB. You may have "
            << "encountered our enemies, "
            << "they seek to destroy all mention and presence of "
            << "THE ORB. They are idiots. " << std::endl;
  do {
    std::cout << "1. Agreed" << std::endl;
    std::cout << "2. Well I don't know about that..." << std::endl;
    std::cout << "> Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> Leader: You are truly a defender of THE ORB. I "
              << "present you with the symbol "
              << "of our cause" << std::endl << "(You receive a shiny "
              << "gold coloured coin)" << std::endl;
    p.playerGet("token");
    do {
      std::cout << "1. How can I travel towards the orb?" << std::endl;
      std::cout << "2. Okay, thanks!" << std::endl;
      std::cout << "> Choose" << std::endl;
      std::cout << "<< ";
      select1 = changeChoice();
    } while (select1 == -1);
    switch (select1) {
    case 1:  // continues
      std::cout << "> Leader: There is a drifter on the edge of town. He "
                << "comes and goes magically, and may have means "
                << "to travel to far lands. "
                << "Though it has been said that the cost is great. "
                << "Good luck. " << std::endl;
    case 2:  // end convo early
      std::cout << "> You're welcome. Goodbye!" << std::endl;
    }
  }
}

void Npc::Drifter(Player& p) {
  int select0, select1, select2;
  std::cout << "> You approach the warrior-cowboy. "
            << "He points a harpoon gun at you and demands you "
            << "identify yourself. " << std::endl;
  do {
    std::cout << "1. I'm the one who will send you to your grave!!"
              << std::endl;
    std::cout << "2. I've been told you know how to travel to ";
    std::cout << "different worlds" << std::endl;
    std::cout << "> Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> Why would you threaten a drifter? YOU DEAD!!!"
              << std::endl;
    p.setPlayerAlive(0);
    return;
  case 2:
    std::cout << "> He lowers his weapon slightly and says "
              << "I may know how "
              << "to travel, but why do you have to leave?" << std::endl;
    do {
      std::cout << "1. THE ORB" << std::endl << "2. I'm not telling "
                << "some idiot dressed like a robo-cowboy" << std::endl;
      std::cout << "> Choose" << std::endl;
      std::cout << "<< ";
      select1 = changeChoice();
    } while (select1 == -1);
    switch (select1) {
    case 1:
      std::cout << "Drifter: Well I suppose I could help you out, "
                << "though it won’t be for free. I’m a man of simple "
                << "things. My harpoon gun, my premium grain leather "
                << "hat, and twinkies. Can’t get enough of em. Bring me "
                << "a couple twinkies and I can send you far away to the "
                << "world where I got my transporter. " << std::endl;
      // check inventory for twinkies, if present then
      // change location to SciFi-Naboot, else return to supermarket
      if (p.searchPlayerInv("twink") == 1) {
        std::cout << "You give the drifter the twinkie you collected."
                  << std::endl;
        std::cout << p.setPlayerLocation(9, p) << std::endl;
        p.playerGive("twink");
        sleep(1);
        return;
      } else {
        std::cout << "Maybe try actually " "examining"
                  << " the supermarket." <<std::endl;
        std::cout << p.setPlayerLocation(6, p) <<std::endl;
        return;
      }
    case 2:
      std::cout << "Not good enough (he raises his harpoon gun back ";
      std::cout << "at your chest)" << std::endl;
      do {
        std::cout << "1. Do your worst!" << std::endl;
        std::cout << "2. Ok, I seek THE ORB" << std::endl;
        std::cout << "> Choose" << std::endl;
        std::cout << "<< ";
        select2 = changeChoice();
      } while (select2 == -1);
      switch (select2) {
      case 1:  // DEATH
        p.setPlayerAlive(0);
        return;
      case 2:
        std::cout << "Drifter: Well I suppose I could help you out,"
                  << " though it won’t "
                  << "be for free. I’m a man of simple things. My harpoon "
                  << "gun, my premium grain leather hat, and twinkies. "
                  << "Can’t get enough of em. Bring me a couple twinkies "
                  << "and I can send you far away to the world where I "
                  << "got my transporter. " << std::endl;
        // check inventory for twinkies, if present then
        // change location to SciFi-Naboot, else return to supermarket
        if (p.searchPlayerInv("twink") == 1) {
          std::cout << "> You give the drifter the twinkie you collected."
                    << std::endl;
          std::cout << "> The drifter points a taser-like device towards ";
          std::cout << "you and you are again rushed through time and ";
          std::cout << "space to a far-away land" << std::endl;
          std::cout << p.setPlayerLocation(9, p) << std::endl;
          p.playerGive("twink");
          return;
        } else {
          std::cout << "> Maybe try actually \"examining\""
                    << " the supermarket." <<std::endl;
          std::cout << p.setPlayerLocation(6, p) << std::endl;

          return;
        }
      }
    }
  }
}

void Npc::JamJam(Player& p) {
  int select0, select1;
  string item;
  std::cout << "> Creature: Hello! Welcome to Naboot! My name is JamJam! "
            << "I trade goods at my shop, would you like to make a trade??"
            << std::endl;
  do {
    std::cout << "1. Sure, what do you have?" << std::endl;
    std::cout << "2. No" << std::endl << "Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    std::cout << "> JamJam pulls out a tray of small devices. Most of them "
              << "seem like junk. One item catches your eye as it looks "
              << "just like the device both Edmund the Bastard and The "
              << "Drifter used to teleport you. There is also a strange "
              << "looking shaft that appears to have a light source on "
              << "one end. " << std::endl;
    do {
      std::cout << "1. Inquire about the teleporter" << std::endl;
      std::cout << "2. Inquire about the potential laser sword" << std::endl;
      std::cout << "Choose" << std::endl;
      std::cout << "<< ";
      select1 = changeChoice();
    } while (select1 == -1);
    switch (select1) {
    case 1:
      std::cout << "> JamJam: This was from an adventurer trying to find"
                << " THE ORB! "
                << "I need some rare wood for something like this" << std::endl;
      p.playerInfo();
      std::cout << "> Choose the item you want to trade." << std::endl;
      getline(std::cin, item);
      // use inventory to select potential trade
      if (p.searchPlayerInv(item) == 1) {
        while (item != "plank") {
          std::cout << "> JamJam: Please trade me wood, if not i will "
                    << "cut you down";
          std::cout << std::endl;
          std::cout << "<< ";
          getline(std::cin, item);
        }
        std::cout << "> JamJam: Thank you for this amazing trade."
                  << std::endl;
        p.playerGive("plank");
        p.playerGet("tele");
      }
      std::cout << "> JamJam: The adventurer told me he traveled many worlds "
                << "in this game, but they couldn't defeat the most important"
                << " test of them all. Java the Hutt has many connections "
                << "and could know more" << std::endl;
      return;

    case 2:
      std::cout << "JamJam: That is one powerful light! But I am saving it "
                << "for Master Fluke." << std::endl;
      return;
    }
  case 2:
    std::cout << "You step away from the trading stand. There does "
              << "not appear to be anything else to do. " << std::endl;
    return;
  }
}

void Npc::Java(Player& p) {
  int select0;
  string itemChoice;
  do {
    std::cout << "1. Java, I have come for THE ORB." << std::endl;
    std::cout << "2. Java good sir, I hear you are a reasonable fellow ";
    std::cout << "and can direct me to THE ORB?" << std::endl;
    std::cout << "> Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  std::cout << "> Java: You are no different than any other "
            << "pathetic traveler. "
            << "You will be an excellent meal for my beast!" << std::endl;
  std::cout << "The floor beneath you gives way and you fall into a pit "
            << "of sand and bones. You hear loud snarls and a giant beast "
            << "comes into view. It is clearly starved and looks dry "
            << "from thirst as well" << std::endl;
  std::cout << "Quick, pick the item from your inventory you would like "
            << "to use to defeat the beast!" << std::endl;
  p.playerInfo();
  getline(std::cin, itemChoice);
  // Give healthTonic to the beast
  if (itemChoice == "hp") {
    if (p.searchPlayerInv("hp") == 1) {
      p.setRancorTest(1);
      std::cout << "> (Good thing you kept that tonic from Gertrude."
                << "The beast falls over and experiences extreme "
                << "gastrointestinal paralysis. Good thing you did "
                << "not drink it.)" << std::endl;
      // Success soto
      std::cout << "> Java: Bring the adventurer up here, "
                << "they show great wisdom. \n"
                << "> You are free to pursue THE ORB and visit the VIP area "
                << "of my cantina. The Snuggler possesses great "
                << "artifacts that may help your quest." << std::endl;
      return;
    } else {
      std::cout << "> You only wish you had picked it up when you had the "
                << "chance. As you are devoured by the Beast." << std::endl;
      // Failure = death
    }
  } else {
    std::cout << "> You have chosen unwisely and are devoured "
              << "by the beast!!!!" << std::endl;
    p.setPlayerAlive(0);
    return;
  }
}

void Npc::Snuggler(Player& p) {  //moth character
  string item;
  std::cout << "> Snuggler: You are the wise traveler that felled"
            << " the beast, no? I hear"
            << " you seek THE ORB. If the price is right, I will part with "
            << "my CUBES. These CUBES contain the sacred numbers of THE ORB."
            << " What do you offer for such a valuable artifact?" << std::endl;
  p.playerInfo();
  std::cout << "> Choose the item to offer: " << std::endl;
  getline(std::cin, item);
  if (p.searchPlayerInv("token") == 1) {
    if (item == "token") {
      p.playerGet("dice");
      p.playerGive(item);
      std::cout << "> (The Snuggler trades you his CUBES containing the "
                << "sacred numbers of THE ORB for your gold coin!\n";
      std::cout << "> Snuggler: The great Admiral Ackbari is wise "
                << "in the ways of "
                << "THE ORB. Seek him at the base on the planet Hothe and "
                << "he may share wisdom for your quest. " << std::endl;
    } else {
      std::cout << "> Snuggler: Please don't insult me! "
                << "I don't want that!" << std::endl;
      std::cout << "> Perhaps finding me something of value, "
                << "possibly gold." << std::endl;
      Snuggler(p);
    }
  } else {
    std::cout << "> Snuggler: You may want to go find what I want "
              << "to get the cubes"
              << std::endl;
  }
}



void Npc::Ackbari(Player& p) {
  int select0;
  string playerChoice;
  std::cout << "> Ackbari: What brings you to the freezing depths of ";
  std::cout << "Hothe? Speak quickly, ";
  std::cout << "we're planning a counter-attack on the empirical DeathORB! "
            << std::endl;
  do {
    std::cout << "1. I love the cold." << std::endl;
    std::cout << "2. I have been told you have wisdom about THE ORB."
              << std::endl;
    std::cout << "> Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1:
    int select1;
    std::cout << "> Ackbari: Well that's dumb. I have heard "
              << "chatter of an adventurer"
              << " seeking THE ORB, is that who you are? " << std::endl;
    do {
      std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
      std::cout << "> Choose";
      std::cout << "<< ";
      select1 = changeChoice();
    } while (select1 == -1);
    switch (select1) {
    case 1:
      goto label1;
    case 2:
      std::cout << "> Ackbari: Then you must be an empirical spy!!"
                << "Prepare to die!" << std::endl;
      p.setPlayerAlive(0);
      return;
    }
  case 2:
label1:
    int droidCombat;
    std::cout << "> Ackbari: Well your timing is perfect. "
              << "Princess Lele has been "
              << "gone longer than usual while on a perimeter check. "
              << "Accompany me to check on her and "
              << "I can give you a secret phrase of THE ORB." << std::endl
              << "> (You load up some haunhauns and head into the blowing snow)"
              << std::endl;
    sleep(1);
    std::cout << "> (After 30 minutes of searching you see a downed haunhaun"
              << " and injured  Princess Lele huddling next to it. Suddenly "
              << "you have several black levitating robots pop up from the"
              << "snow around you!!]" << std::endl;
    std::cout << "Press [ENTER] to continue!\n";
    std::cin.get();
    std::cout << "> Ackbari: IT'S A TRAP! " << std::endl;
    // Droid Combat
    std::cout << "> You look into your bag and see something at the "
              << "very bottom labeled EMP. " << std::endl;
    std::cout << "> Do you use it? If so type yes, anything else for no."
              << std::endl;
    std::cout << "<< ";
    getline(std::cin, playerChoice);
    if (playerChoice == "yes")
      droidCombat = 1;
    else
      droidCombat = 0;
    if (droidCombat == 1) {
      std::cout << "\n";
      std::cout << "(You clearly have the luck of THE ORB on your side. The "
                "EMP shuts down all the droids and you save the crew";
      std::cout << "> Ackbari: Well done seeker! I can get the Princess back "
                << "to the the base. Take this. It's one of the secret "
                << "phrases for THE ORB. It is \"beatus\". "
                << "Use your teleporter to go to "
                << "Garfield's lair. He has the last phrase you will need. "
                << "But beware, he is a mighty competitor and will not give "
                << "the phrase to the unworthy! " << std::endl;
      p.playerGet("p2");
      return;
      // change to combat puzzle maybe
    } else {
      std::cout << "> (You are mortally wounded, and quickly of your wound ";
      std::cout << "in the freezing cold)" << std::endl;
      p.setPlayerAlive(0);
      return;
    }
  }
}


void Npc::Garfield(Player& p) {
  int select0;
  std::cout << "> Garfield: Hello. Welcome to Garfield Kart. "
            << "Word of your quest proceeds you. I "
            << "am the keeper of the last secret phrase of THE ORB. If you "
            << "can defeat me in a race I will give it to you, but if you "
            << "lose - it will cost you your life. Are you ready to begin? "
            << std::endl;
  do {
    std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
    std::cout << "Choose" << std::endl;
    std::cout << "<< ";
    select0 = changeChoice();
  } while (select0 == -1);
  switch (select0) {
  case 1: {
    int raceWin;
    // start kartRace
    garRace gr;
    RacingPuzzle race;
    std::cout << gr.loadLocInfo() << std::endl;
    raceWin = race.Race();
    if (raceWin == 1) {
      garPostRace gpr;
      std::cout << gpr.loadLocInfo() << std::endl;
      p.playerGet("p3");
      return;
    }
  }
  case 2:
    std::cout << "> Garfield: Okay. Take your time. I will stay here until "
              << "you want to race." << std::endl;
    return;
    // back to room
  }
}

