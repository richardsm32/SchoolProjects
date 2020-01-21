#ifndef INCLUDE_ISLANDOFFOOLS_H
#define INCLUDE_ISLANDOFFOOLS_H
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived Locations
* class to represent the "Island of Fools" location
*/



class IslandOfFools: public Locations {
 public:
  /**
  * @brief Default constructor to create an
  * IslandOfFools object.
  */
  IslandOfFools();
  /**
  * @brief Progresses the user to the
  * Island of Fools.
  */
  string loadLocInfo();
};
#endif
