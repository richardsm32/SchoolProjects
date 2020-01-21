/*
* CPSC 2720 Course Project - Team "Akbar"
* Spring 2019
* Copyright 2019 Lorenzo Conrad <lorenzo.conrad@uleth.ca>,
* Ricky Bueckert <ricky.bueckert@uleth.ca>,
* Mathew Richards <mathew.richards@uleth.ca>.
*/

#include "Player.h"
#include "Exceptions.h"
#include "Npc.h"
#include "KartRace.h"
#include "IslandOfFools.h"
#include "TheOrb.h"
#include "EdgeVillage.h"
#include "Tavern.h"
#include "VillageSquare.h"
#include "Slums.h"
#include "InnerCity.h"
#include "SuperMarket.h"
#include "Outpost.h"
#include "OuterCity.h"
#include "Naboot.h"
#include "Tatooined.h"
#include "Hothe.h"
#include "GarfieldsLair.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using std::string;
using std::vector;

Player::Player() {
  playerAlive = 1;
  playerLocation = 1;
  rancorTest = 0;
}

int Player::changePChoice() {
  string var;
  getline(std::cin, var);
  try {
    int c = stoi(var);
    return c;
  } catch (const std::invalid_argument& e) {
    return -1;
  }
}


int Player::getPlayerAlive() {
  return playerAlive;
}




void Player::setPlayerAlive(int status) {
  playerAlive = status;
}


string Player::playerHelp() {
  return
    "> Welcome to the help tab: \n"
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
    "To quit the game at any time use ctrl + c.\n";
}




void Player::playerUse(Player& p) {
  string yes;
  string item;
  playerInfo();
  std::cout << "> Which item would you like to use?" << std::endl;
  std::cout << ">> Please enter: " << std::endl;
  std::cout << "- hp for Health Tonic" << std::endl;
  std::cout << "- dice for Loaded Dice" << std::endl;
  std::cout << "- pamph for Pamphlet" << std::endl;
  std::cout << "- plank for Nailed Plank" << std::endl;
  std::cout << "- twink for Twinkie" << std::endl;
  std::cout << "- token for Gold Token" << std::endl;
  std::cout << "- tele for Teleporter" << std::endl;
  std::cout << "<< ";
  getline(std::cin, item);
  if (playerInv.searchInventory(item) == 0) {
    std::cout << "> That is and invalid item or you do not have "
              << "it in your inventory. Enter yes to try again "
              << "anything else to exit use item" << std::endl;
    std::cout << "<< ";
    getline(std::cin, yes);
    if (yes == "yes")
      playerUse(p);
  } else if (item == "hp" && playerInv.searchInventory(item) == 1) {
    std::cout << "> Why would you drink something Gertrude gave you? "
              << "Do you have a death wish? Well, wish granted! YOU ARE DEAD!"
              << std::endl;
    setPlayerAlive(0);
  } else if (item == "dice" && playerInv.searchInventory(item) == 1) {
    std::cout << "> Your loaded dice roll 6, 7, 2." << std::endl;
  } else if (item == "pamph" && playerInv.searchInventory(item) == 1) {
    std::cout << "> Using the pamphlet is pointless, "
              << "I would recommend examining the pamphlet, "
              << "it may reveal something to you." << std::endl;
  } else if (item == "plank" && playerInv.searchInventory(item) == 1) {
    if (playerLocation == 5) {
      std::cout << "> You swing the nailed plank with all your might but"
                << " quickly realize you are swinging at nothing."
                << " And give up." << std::endl;
    }
  } else if (item == "twink" && playerInv.searchInventory(item) == 1) {
    if (playerLocation == 8) {
      Npc c;
      c.Drifter(p);
    } else {
      std::cout << "> You can eat them if you want but somehow"
                << " despite being a virtual character you are "
                << "allergic to gluten."
                << " These might be useful later." << std::endl;
    }
  } else if (item == "token" && playerInv.searchInventory(item) == 1) {
    if (playerLocation == 10) {
      if (rancorTest == 1) {
        Npc c;
        c.Snuggler(p);
      } else {
        std::cout << "> You flip the coin and it lands on the side! "
                  << "You put the token back into your pocket, thinking"
                  <<" it could probably be useful somewhere else."<< std::endl;
      }
    } else {
      std::cout << "> You flip the coin and it lands on the side! "
                << "You put the token back into your pocket, thinking"
                <<" it could probably be useful somewhere else."<< std::endl;
    }
  } else if (item == "tele" && playerInv.searchInventory(item) == 1) {
    playerTele(p);
  }
}


void Player::playerGive(string sitem) {
  playerInv.subItem(sitem);
}


string Player::numberToLocation(int numloc) {
  if (numloc == 1) {
    return "> Edge of Village";
  } else if (numloc == 2) {
    return "> Tavern";
  } else if (numloc == 3) {
    return "> Village Square";
  } else if (numloc == 4) {
    return "> Slums";
  } else if (numloc == 5) {
    return "> Inner City";
  } else if (numloc == 6) {
    return "> Supermarket";
  } else if (numloc == 7) {
    return "> Outpost";
  } else if (numloc == 8) {
    return "> Outer City";  // inventory function?
  } else if (numloc == 9) {
    return "> Naboot";
  } else if (numloc == 10) {
    return "> Tatooined";
  } else if (numloc == 11) {
    return "> Hothe";
  } else if (numloc == 12) {
    return "> Garfields Lair";
  } else if (numloc == 13) {
    return "> The Orb";
  } else if (numloc == 14) {
    return "> Island of Fools";
  } else {
    return "> That is not a valid location id";
  }
}

void Player::setName(string name) {
  playerName = name;
}

string Player::getName() {
  return playerName;
}

void Player::playerInfo() {
  std::cout << ">> " << playerName << ",";
  std::cout << " this your current inventory: " << std::endl;
  int indexStore = 0;
  for (int i = 0; i < 11; i++) {
    if (playerInv.getInven(i) == 1) {
      std::cout << playerInv.findItem(i);
      indexStore = i +1;
      break;
    }
  }
  for (int i = indexStore; i < 11; i++)
    if (playerInv.getInven(i) == 1) {
      std::cout << ", " << playerInv.findItem(i);
    }
  std::cout << std::endl;
}





void Player::playerAction(string action, Player& p) {
  string item;
  if (action == "use") {
    playerUse(p);
  } else if (action == "examine") {
    playerExamine(p);
  } else if (action == "travel") {
    playerTravel(p);
  } else if (action == "talk") {
    playerTalk(p);
  } else if (action == "help") {
    std::cout << playerHelp() << std::endl;
  } else if (action == "save") {
    save(playerName, p);
  } else if (action == "load") {
    load(playerName, p);
  } else if (action == "give") {
    p.playerInfo();
    std::cout << "> Choose the item to offer: " << std::endl;
    std::cout << "<< ";
    getline(std::cin, item);
    playerGive(item);
  } else {
    std::cout << "> That action does not exist!"
              << " Please choose another action." << std::endl;
  }
}


void Player::playerTele(Player& p) {
  int newlocation;
  std::cout << ">> Your current location: ";
  std::cout << numberToLocation(playerLocation) << std::endl;
  do {
    std::cout << "> These are the locations you can travel to: ";
    std::cout << "(enter the integer)" << std::endl;
    std::cout << "1 for the Edge of Village" << std::endl;
    std::cout << "2 for the Tavern" << std::endl;
    std::cout << "3 for the Village Square" << std::endl;
    std::cout << "4 for the Slums" << std::endl;
    std::cout << "5 for the Inner City" << std::endl;
    std::cout << "6 for the SuperMarket" << std::endl;
    std::cout << "7 for the Outpost" << std::endl;
    std::cout << "8 for the Outer City" << std::endl;
    std::cout << "9 for Naboot" << std::endl;
    std::cout << "10 for Tatooined" << std::endl;
    std::cout << "11 for Hothe" << std::endl;
    std::cout << "12 for the Garfields Lair" << std::endl;
    std::cout << "13 for The Orb" << std::endl;
    std::cout << "14 for the Island of Fools" << std::endl;
    std::cout << "<< ";
    newlocation = changePChoice();
  } while (newlocation == -1);
  try {
    if (newlocation >= 15 || newlocation <= 0) {
      std::cout << "You have entered an invalid location!!" << std::endl;
      throw location_error("invalid location");
    } else {
      std::cout << setPlayerLocation(newlocation, p) << std::endl;
    }
  } catch (const location_error& e) {}
}


void Player::playerGet(string item) {
  playerInv.addItem(item);
}


int Player::searchPlayerInv(string item) {
  return playerInv.searchInventory(item);
}


string Player::setPlayerLocation(int loc, Player& p) {
  playerLocation = loc;
  if (loc == 1) {
    edgeVillage vil;
    return vil.loadLocInfo();
  } else if (loc == 2) {
    Tavern t;
    return t.loadLocInfo();
  } else if (loc == 3) {
    villageSquare vsq;
    return vsq.loadLocInfo();
  } else if (loc == 4) {
    Slums s;
    return s.loadLocInfo();
  } else if (loc == 5) {
    innerCity ic;
    return ic.loadLocInfo();
  } else if (loc == 6) {
    superMarket sm;
    return sm.loadLocInfo();
  } else if (loc == 7) {
    outpost o;
    return o.loadLocInfo();
  } else if (loc == 8) {
    outerCity oc;
    return oc.loadLocInfo();
  } else if (loc == 9) {
    naboot n;
    return n.loadLocInfo();
  } else if (loc == 10) {
    tatooined t;
    return t.loadLocInfo();
  } else if (loc == 11) {
    hothe h;
    return h.loadLocInfo();
  } else if (loc == 12) {
    garfieldsLair gl;
    return gl.loadLocInfo();
  } else if (loc == 13) {
    TheOrb orb;
    orb.enterPass(p);
    return "";
  } else if (loc == 14) {
    IslandOfFools fool;
    p.setPlayerAlive(0);
    return fool.loadLocInfo();
  } else {
    return "That is not a valid location you entered.";
  }
}


void Player::playerTravel(Player& p) {
  int loc = playerLocation;
  if (playerLocation == 4) {
    std::cout << "> You hear a whisper saying in order to travel you "
              << "must pass my test." << std::endl;
  } else if (playerLocation == 8) {
    std::cout << "> A figure appears and says \"In order to travel from this "
              "place you must get me what I want.\"" << std::endl;
  } else {
    loc++;
    std::cout << p.setPlayerLocation(loc, p) << std::endl;
  }
}






void Player::playerTalk(Player& p) {
  Npc c;
  string npcName;
  if (playerLocation == 1) {
    c.Gertrude(p);
  } else if (playerLocation == 2) {
    std::cout << "> Who would you like to talk to?"<< std::endl;
    std::cout << "Bartender or Simon" << std::endl;
    std::cout << "<< ";
    getline(std::cin, npcName);
    if (npcName == "Bartender") {
      c.Bartender();
    } else if (npcName == "Simon") {
      c.Simon(p);
    } else {
      std::cout << "> There is no one here with that name!!"
                << "You may want to try putting in the name as its written."
                << "> If not, then we'll be here for a while..." << std::endl;
      playerTalk(p);
    }
  } else if (playerLocation == 3) {
    c.Roy(p);
  } else if (playerLocation == 4) {
    c.Edmund(p);
  } else if (playerLocation == 5) {
    std::cout << "> You just killed the only person you could talk to."
              << std::endl;
  } else if (playerLocation == 6) {
    std::cout << "> You are in an abandoned super market, "
              << "there is no-one around to talk to." <<std::endl;
  } else if (playerLocation == 7) {
    c.OutpostLeader(p);
  } else if (playerLocation == 8) {
    c.Drifter(p);
  } else if (playerLocation == 9) {
    c.JamJam(p);
  } else if (playerLocation == 10) {
    if (rancorTest == 1) {
      c.Snuggler(p);
    } else {
      c.Java(p);
    }
  } else if (playerLocation == 11) {
    c.Ackbari(p);
  } else if (playerLocation == 12) {
    c.Garfield(p);
  } else if (playerLocation == 13) {
    std::cout <<
              "> You are amazed by the orb and are rendered speechless"
              << std::endl;
  }
}


string Player::examineRoom(Player& p) {
  if (playerLocation == 4) {
    setPlayerAlive(0);
    return "> You see a hole in the wall of a shack, and as you look "
           "inside you are mauled by hundreds of rats and eaten alive!!";
  } else if (playerLocation == 3) {
    return "> As you examine the statue, the statue says: This monument "
           "was erected in the Year of Our ORB 7412, to THE perfect all "
           "knowing ORB.";
  } else if (playerLocation == 6) {
    p.playerGet("twink");
    return "> You see some twinkies on the ground so you pick one up and "
           "put it in your inventory.";
  } else {
    return "> There is nothing of interest in this location.";
  }
}




void Player::playerExamine(Player& p) {
  string choice, itemChoice;
  std::cout << "> Would you like to examine the room or "
            << "items in your inventory?" << std::endl;
  std::cout << ">> Enter \"inventory\" or \"room.\"" << std::endl;
  std::cout << "<< ";
  getline(std::cin, choice);
  if (choice == "inventory") {
    playerInfo();
    std::cout << "> Enter the item you would like to examine." <<std::endl;
    std::cout << "<< ";
    getline(std::cin, itemChoice);
    std::cout << playerInv.examineInv(itemChoice) << std::endl;
  } else {
    std::cout << examineRoom(p) << std::endl;
  }
}

void Player::save(string filename, Player& p) {
  std::ofstream fs;
  fs.open(filename, std::ios::trunc);
  if (fs.is_open()) {
    fs << playerName << std::endl;
    for (auto i : playerInv.getAll()) {
      fs << i << " ";
    }
    fs << std::endl;
    fs << playerAlive << std::endl;
    fs << playerLocation << std::endl;
    fs << rancorTest << std::endl;
    std::cout << "> " << playerName << " file saved." << std::endl;
    fs.close();
    std::cout << "Would you like to Quit the game?" << std::endl;
    std::cout << "Enter \"yes\" for quit." << std::endl;
    string quit;
    getline(std::cin, quit);
    if (quit == "yes") {
      p.setPlayerAlive(0);
      return;
    }
  } else {
    std::cout << "> File could not be saved."<< std::endl;
  }
}

void Player::load(string filename, Player& p) {
  std::ifstream fs;
  fs.open(filename);
  if (fs.is_open()) {
    getline(fs, playerName);
    vector<int>& inv = playerInv.getAll();
    for (size_t i = 0; i < inv.size(); i++) {
      int k;
      fs >> k;
      inv[i] = k;
    }
    fs >> playerAlive;
    fs >> playerLocation;
    fs >> rancorTest;
    std::cout << "> " << playerName << " file loaded." << std::endl;
    std::cout << setPlayerLocation(playerLocation, p) << std::endl;
    fs.close();
  } else {
    std::cout << "> File error, no such name exists or load file was "
              << "corrupted." << std::endl;
  }
}

void Player::setRancorTest(int ranctest) {
  rancorTest = ranctest;
}

int Player::getPlayerLocation() {
  return playerLocation;
}


  int Player::getRancorTest() {
    return rancorTest;
  }
