#ifndef INCLUDE_THEORB_H
#define INCLUDE_THEORB_H
#include "Player.h"
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived Locations class to represent The Orb. Game
* start and endpoint.
*/


class TheOrb : public Locations {
 public:
  /**
  * @brief Creates a TheOrb object.
  */
  TheOrb();
  /**
  * @brief Loads the info needed for TheOrb
  *  location.
  */
  string loadLocInfo();
  /**
  * @brief Starts the game (transports player
  * to the first location in the game.)
  */
  void gazeOrb();
  /**
  * @brief Prompts the Player for the password
  * If the password is entered properly, the
  * game is completed.
  */
  void enterPass(Player&);
};
#endif
