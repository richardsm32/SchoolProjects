#ifndef HOTHE_H_INCLUDED
#define HOTHE_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "hothe" location
*/



class hothe: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * hothe object.
  */
  hothe();
  /**
  * @brief Loads the info needed for the hothe
  *  location.
  */
  string loadLocInfo();
};


#endif // HOTHE_H_INCLUDED
