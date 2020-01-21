#ifndef GARPOSTRACE_H_INCLUDED
#define GARPOSTRACE_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "GarPostRace"
* location.
*/


class garPostRace: public Locations {
 public:
  /**
  * @brief Creates a garPostRace object.
  */
  garPostRace();
  /**
  * @brief Loads the info needed for the GarPostRace
  *  location.
  */
  string loadLocInfo();
};


#endif // GARPOSTRACE_H_INCLUDED
