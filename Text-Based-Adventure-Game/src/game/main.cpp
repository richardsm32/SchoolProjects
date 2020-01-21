#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "Player.h"
#include "Game.h"
#include "TheOrb.h"
using std::string;


int main () {
  string name;
  TheOrb orb;
  std::cout << " _____ _   _  _____   _________________ " << std::endl;
  std::cout << "|_   _| | | ||  ___| |  _  | ___ \\ ___ \\" << std::endl;
  std::cout << "  | | | |_| || |__   | | | | |_/ / |_/ /" << std::endl;
  std::cout << "  | | |  _  ||  __|  | | | |    /| ___ \\" << std::endl;
  std::cout << "  | | | | | || |___  \\ \\_/ / |\\ \\| |_/ /" << std::endl;
  std::cout << "  \\_/ \\_| |_/\\____/   \\___/\\_| \\_\\____/ " << std::endl;
  Player p;
  Game g;
  std::cout << "> Enter the name of your player: " << std::endl;
  std::cout << "> If loading, enter previous player name exactly" << std::endl;
  std::cout << "<< ";
  getline(std::cin, name);
  p.setName(name);
  std::cout << "> " << p.getName() << ", welcome to the game!!" << std::endl;
  p.playerInfo();
  std::cout << "> Your starting inventory is empty, throughout the "
            <<"game you can collect items to fill your inventory." << std::endl;
  std::cout << p.playerHelp() << std::endl;
  g.startMenu();
  orb.gazeOrb();
  bool runstatus = g.getGameRun();
  g.runGame(runstatus, p);
  return 0;
}
