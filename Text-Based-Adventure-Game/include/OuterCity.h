#ifndef OUTERCITY_H_INCLUDED
#define OUTERCITY_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "outerCity" location
*/


class outerCity: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * outerCity object.
  */
  outerCity();
  /**
  * @brief Loads the info needed for the
  * outerCity location.
  */
  string loadLocInfo();
};


#endif // OUTERCITY_H_INCLUDED
