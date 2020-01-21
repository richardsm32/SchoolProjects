#ifndef TATOOINED_H_INCLUDED
#define TATOOINED_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "tatooined" location
*/


class tatooined: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * tatooined object.
  */
  tatooined();
  /**
  * @brief Loads the info needed for the tatooined
  *  location.
  */
  string loadLocInfo();
};
#endif // TATOOINED_H_INCLUDED
