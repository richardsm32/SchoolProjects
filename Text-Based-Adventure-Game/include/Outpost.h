#ifndef OUTPOST_H_INCLUDED
#define OUTPOST_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "outpost" location
*/


class outpost: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * outpost object.
  */
  outpost();
  /**
  * @brief Loads the info needed for the outpost
  * in the city.
  */
  string loadLocInfo();
};


#endif // OUTPOST_H_INCLUDED
