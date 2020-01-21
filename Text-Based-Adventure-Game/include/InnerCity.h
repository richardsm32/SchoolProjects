#ifndef INNERCITY_H_INCLUDED
#define INNERCITY_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "innerCity" location
*/


class innerCity: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * innerCity object.
  */
  innerCity();
  /**
  * @brief Loads the info needed for inner
  * city  location.
  */
  string loadLocInfo();
};

#endif // INNERCITY_H_INCLUDED
