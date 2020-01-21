#ifndef TAVERN_H_INCLUDED
#define TAVERN_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "Tavern" location
*/


class Tavern: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * Tavern object.
  */
  Tavern();
  /**
  * @brief Loads the info needed for Tavern in the
  * village.
  */
  string loadLocInfo();
};


#endif // TAVERN_H_INCLUDED
