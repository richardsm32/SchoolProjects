#ifndef SLUMS_H_INCLUDED
#define SLUMS_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "Slums" location
*/


class Slums: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * slums object.
  */
  Slums();
  /**
  * @brief Loads the info needed for slums in the
  * village.
  */
  string loadLocInfo();
};

#endif // SLUMS_H_INCLUDED
