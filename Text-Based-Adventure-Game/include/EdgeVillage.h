#ifndef EDGEVILLAGE_H_INCLUDED
#define EDGEVILLAGE_H_INCLUDED
#include "Locations.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations
* class to represent the "Edge of the Village" location
*/


class edgeVillage: public Locations {
 public:
  /**
  * @brief Default constructor to create a
  * edgeVillage object.
  */
  edgeVillage();
  /**
  * @brief Loads the info needed for edge of the
  * village.
  */
  string loadLocInfo();
};
#endif // EDGEVILLAGE_H_INCLUDED
