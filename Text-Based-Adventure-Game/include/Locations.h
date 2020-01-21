#ifndef LOCATIONS_H_INCLUDED
#define LOCATIONS_H_INCLUDED
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Base class for all the different locations
*/


class Locations {
 public:
  /**
  * @brief Default constructor to create an
  * Location object.
  */
  Locations();
  /**
  * @brief Loads info for different location.
  */
  virtual string loadLocInfo() = 0;
};

#endif // LOCATIONS_H_INCLUDED
