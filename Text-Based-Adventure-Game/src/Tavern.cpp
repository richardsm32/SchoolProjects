#include "Tavern.h"
#include <string>
using std::string;

Tavern::Tavern() {
}

string Tavern::loadLocInfo() {
  return "\n\n"
         "**********************************************\n"
         "> The tavern is known as \"The Prancing Floutist\". "
         "Inside there are only a few people. The bartender, "
         "a gambler tucked away in a corner, and the namesake "
         "of the place - a floutist performing ballads whilst "
         "dancing around the establishment.\n";
}
