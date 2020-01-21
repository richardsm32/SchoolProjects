#ifndef VILLAGESQUARE_H_INCLUDED
#define VILLAGESQUARE_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "Village Square" location
*/


class villageSquare: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * villageSquare object.
  */
  villageSquare();
  /**
  * @brief Loads the info needed for the
  * village Square.
  */
  string loadLocInfo();
};



#endif // VILLAGESQUARE_H_INCLUDED
