/**
* @author Mathew Richards, Lorenzo Conrad, Ricky Bueckert
* @date 5 Mar 2019
* @brief Implementation of a player's inventory in The Orb
*/
#include "Inventory.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

//create inventory
Inventory::Inventory() : inventory(vector<int>(11, 0)) {}


//search inventory
int Inventory::searchInventory(string sitem) {
  if (sitem == "hp")
    return inventory[0];
  else if (sitem == "dice")
    return inventory[1];
  else if (sitem == "pamph")
    return inventory[2];
  else if (sitem == "plank")
    return inventory[3];
  else if (sitem == "twink")
    return inventory[4];
  else if (sitem == "token")
    return inventory[5];
  else if (sitem == "tele")
    return inventory[6];
  else if (sitem == "soto")
    return inventory[7];
  else if (sitem == "p1")
    return inventory[8];
  else if (sitem == "p2")
    return inventory[9];
  else if (sitem == "p3")
    return inventory[10];
  else
    return 0;
}

string Inventory::findItem(int index) {
  if (index == 0) {
    return "> Health Tonic";
  } else if (index == 1) {
    return "> Loaded Die";
  } else if (index == 2) {
    return "> Pamphlet";
  } else if (index == 3) {
    return "> Nailed Plank";
  } else if (index == 4) {
    return "> Twinkie";
  } else if (index == 5) {
    return "> Gold Token";
  } else if (index == 6) {
    return "> Teleporter";
  } else if (index == 7) {
    return "> Sword of the ORB";
  } else if (index == 8) {
    return "> Password 1";
  } else if (index == 9) {
    return "> Password 2";
  } else if (index == 10) {
    return "> Password 3";
  } else {
    throw item_error("Index error");
    return "> Index error";
  }
}

void Inventory::addItem(string gitem) {
  if (gitem == "hp") {
    inventory[0] = 1;
  } else if (gitem == "dice") {
    inventory[1] = 1;
  } else if (gitem == "pamph") {
    inventory[2] = 1;
  } else if (gitem == "plank") {
    inventory[3] = 1;
  } else if (gitem == "twink") {
    inventory[4] = 1;
  } else if (gitem == "token") {
    inventory[5] = 1;
  } else if (gitem == "tele") {
    inventory[6] = 1;
  } else if (gitem == "soto") {
    inventory[7] = 1;
  } else if (gitem == "p1") {
    inventory[8] = 1;
    pass1 = "orbis";
  } else if (gitem == "p2") {
    inventory[9] = 1;
    pass2 = "beatus";
  } else if (gitem == "p3") {
    inventory[10] = 1;
    pass3 = "est";
  } else {
    throw item_error("> No such item exists");
  }
}

void Inventory::subItem(string sitem) {
  if (sitem == "hp") {
    inventory[0] = 0;
  } else if (sitem == "dice") {
    inventory[1] = 0;
  } else if (sitem == "pamph") {
    inventory[2] = 0;
  } else if (sitem == "plank") {
    inventory[3] = 0;
  } else if (sitem == "twink") {
    inventory[4] = 0;
  } else if (sitem == "token") {
    inventory[5] = 0;
  } else if (sitem == "tele") {
    inventory[6] = 0;
  } else if (sitem == "soto") {
    inventory[7] = 0;
  } else if (sitem == "p1") {
    inventory[8] = 0;
    pass1 = "orbis";
  } else if (sitem == "p2") {
    inventory[9] = 0;
    pass2 = "beatus";
  } else if (sitem == "p3") {
    inventory[10] = 0;
    pass3 = "est";
  } else {
    throw item_error("> No such item exists");
  }
}

string Inventory::password1() {
  if (inventory[8] == 1)
    return pass1;
  else
    return "> You do not have password 1";
}

string Inventory::password2() {
  if (inventory[9] == 1)
    return pass2;
  else
    return "> You do not have password 2";
}

string Inventory::password3() {
  if (inventory[10] == 1)
    return pass3;
  else
    return "> You do not have password 3";
}

int Inventory::getInven(int index) {
  return inventory.at(index);
}

string Inventory::examinePamph() {
  return "> THE ORB is the greatest thing in all of history."
         " It has been 3007 years since anyone has appeared after visiting "
         "THE ORB. The most supernal goal one can have in life is to return"
         " to THE ORB with an understanding of it's majesty!!! (Written "
         "by GERTRUDE! Contact me for all your HEALTH TONIC needs!!!";
}

string Inventory::examineInv(string eitem) {
  if (eitem == "hp")
    return "> The Health Tonic seems to be glowing, "
           "making all who see it uneasy.";
  else if (eitem == "dice")
    return "> The Loaded Dice look like a plain old ordinary dice "
           "could be vary useful when gambling.";
  else if (eitem == "pamph")
    return examinePamph();
  else if (eitem == "plank")
    return "> The nailed plank looks like something out of the "
           "Walking Dead. Could be useful in a fight.";
  else if (eitem == "twink")
    return "> It's a twinkie, it looks delicious but you are "
            "gluten intolerant!";
  else if (eitem == "token")
    return "> The Gold Token looks like an ancient relic but really "
           "it is just a gold chocolate coin.";
  else if (eitem == "tele")
    return "> The outside of the teleporter looks plain with a "
           "few dials on it controlling the locations.";
  else if (eitem == "soto")
    return "> I don't know how you figured this one out, it is "
           "NOT IN THE DAMN GAME. FRICK!!!!!!!!!!!";
  else if (eitem == "p1")
    return "> Password 1 is: \"orbis\"";
  else if (eitem == "p2")
    return "> Password 2 is: \"beatus\"";
  else if (eitem == "p3")
    return "> Password 3 is: \"est\"";
  else
    return "> You don't have an item by that name, try examining again";
}
