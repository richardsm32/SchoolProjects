/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived Locations class to represent The Orb. Game
* start and endpoint.
*/

#include "TheOrb.h"
#include <iostream>
#include <string>
using std::string;

TheOrb::TheOrb() {
}

string TheOrb::loadLocInfo() {
  return "\n\n"
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
         "orb.\n";
}

void TheOrb::gazeOrb() {
  string action;
  do {
    std::cout << "> What would you like to do? ";
    std::cout << "(You may want to examine or gaze at the orb)" << std::endl;
    std::cout << "<< ";
    getline(std::cin, action);
    if (action == "examine") {
      std::cout << "> There is nothing here but the orb." << std::endl;
    } else if (action != "examine" && action != "gaze") {
      std::cout << "> Come on the game just started. Follow the"
                << " instructions please!!" << std::endl;
    }
  } while (action != "gaze");
  std::cout << "> Your mind is transfixed by the deep cosmic energy "
            << "emanating from the centre of THE ORB. You feel a sudden rush "
            << "as your body is thrown through time and space for an "
            << "unbelievable distance. " << std::endl;
}

void TheOrb::enterPass(Player & p) {
  string thePassword;
  std::cout << "> The Orb demands you enter the password in perfect form.\n";
  std::cout << "<< ";
  getline(std::cin, thePassword);
  if (thePassword == "orbis beatus est") {
    std::cout << ">> THE ORB GLOWS BRIGHTER AND BRIGHTER IN INTENSITY AND"
              << " YOUR MIND FILLS WITH PERFECTION AS YOU ARE SLOWLY CONSUMED"
              << " AND BECOME PART OF THE ORB!!!!!!!!" << std::endl;
    std::cout << "Congratulations, you have won the game!\n";
    p.setPlayerAlive(0);
  }
}
