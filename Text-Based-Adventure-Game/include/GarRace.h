#ifndef GARRACE_H_INCLUDED
#define GARRACE_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "GarRace"
* location.
*/


class garRace: public Locations {
 public:
  /**
  * @brief Creates a garRace object
  */
  garRace();
  /**
  * @brief Loads the info needed for the GarRace
  *  location.
  */
  string loadLocInfo();
};


#endif // GARRACE_H_INCLUDED
