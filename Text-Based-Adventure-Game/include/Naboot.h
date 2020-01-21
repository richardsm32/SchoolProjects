#ifndef NABOOT_H_INCLUDED
#define NABOOT_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "naboot" location
*/


class naboot: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * naboot object.
  */
  naboot();
  /**
  * @brief Loads the info needed for naboot
  *  location.
  */
  string loadLocInfo();
};


#endif // NABOOT_H_INCLUDED
