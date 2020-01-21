#include "InnerCity.h"
#include <string>
using std::string;

innerCity::innerCity() {
}

string innerCity::loadLocInfo() {
  return "\n\n"
         "**********************************************\n"
         "> The rush of transport leaves you feeling disoriented "
         "and groggy. As you start to come to your senses you "
         "realize there is imminent danger. You are in a "
         "ruined city, with a dangerous looking mercenary "
         "in the distance quickly moving in. You see a nailed "
         "plank nearby and quickly pick it up in preparation for a fight!\n";
}
