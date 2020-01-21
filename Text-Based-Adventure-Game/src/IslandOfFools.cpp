#include "IslandOfFools.h"
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived Locations
* class to represent the "Island of Fools" location
*/

IslandOfFools::IslandOfFools() {
}

string IslandOfFools::loadLocInfo() {
  return "\n\n"
         "**********************************************\n"
         "> You probably saw this in the menu and thought "
         "it was an interesting place to visit. Sadly you're very wrong."
         " This is a popular battle royale game for "
         "teenagers. It is a terrible and toxic place. The toxicity "
         "acts quickly and you feel all body systems shutting down. "
         "You die a quick and painful death!\n";
}
