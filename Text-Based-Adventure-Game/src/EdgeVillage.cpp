#include "EdgeVillage.h"
#include <unistd.h>
#include <string>
using std::string;


edgeVillage::edgeVillage() {
}

string edgeVillage::loadLocInfo() {
  sleep(4);
  return "\n\n"
  "**********************************************\n"
  "> You are thrown into some shrubbery on the edge of a "
  "medieval-looking village. You land on an old backpack, and "
  "decide it's a good idea to put it on. "
  "Then a crazed woman rushes over to meet you.\n";
}
