#ifndef GARFIELDSLAIR_H_INCLUDED
#define GARFIELDSLAIR_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "Garfield's
* Lair" location.
*/


class garfieldsLair: public Locations {
 public:
  /**
  * @brief Creates a garfieldsLair object.
  */
  garfieldsLair();
  /**
  * @brief Loads the info needed for the Garfield Lair
  *  location.
  */
  string loadLocInfo();
};

#endif // GARFIELDSLAIR_H_INCLUDED
