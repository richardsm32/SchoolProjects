#include "SuperMarket.h"
#include <string>
using std::string;

superMarket::superMarket() {
}

string superMarket::loadLocInfo() {
  return "\n\n"
         "**********************************************\n"
         "> After winding through the alleyway you find the back "
         "entrance to an abandoned grocery store. It has been heavily "
         "looted but there are some supplies left. You see some "
         "compelling propaganda brochures and some unhealthy "
         "food items.\n";
}
