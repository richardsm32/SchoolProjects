#include "Outpost.h"
#include <string>
using std::string;

outpost::outpost() {
}

string outpost::loadLocInfo() {
  return "\n\n"
         "**********************************************\n"
         "> You venture to a re-purposed factory a short distance "
         "away. You are met by guards almost as soon as the "
         "factory is in sight. You explain to them you seek "
         "to return to THE ORB. This seems to please them and "
         "they are less hostile towards you. They take you "
         "to the leader.\n";
}
