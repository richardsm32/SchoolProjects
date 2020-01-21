#ifndef SUPERMARKET_H_INCLUDED
#define SUPERMARKET_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "superMarket" location
*/


class superMarket: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * superMarket object.
  */
  superMarket();
  /**
  * @brief Loads the info needed for the
  * supermarket location.
  */
  string loadLocInfo();
};

#endif // SUPERMARKET_H_INCLUDED
