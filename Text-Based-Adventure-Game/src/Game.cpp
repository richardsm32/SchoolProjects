#include "Game.h"
#include "Exceptions.h"
#include "Player.h"
#include "Npc.h"
#include "TheOrb.h"
#include "EdgeVillage.h"
#include <unistd.h>
#include <iostream>
#include <string>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief "General UI for the game, allows users to start
* and stop the game, etc"
*/


Game::Game() {
  gamerun = true;
}

void Game::startMenu() {
  TheOrb orb;
  std::cout << "**********************************************" << std::endl;
  std::cout << ">> Press [ENTER] to begin your adventure! " << std::endl;
  std::cin.get(); // require ENTER key to continue.
  sleep(1);
  std::cout << orb.loadLocInfo() << std::endl;
}

void Game::runGame(bool gamerun, Player& p) {
  edgeVillage vil;
  Npc gnpc;
  vil.loadLocInfo();
  gnpc.Gertrude(p);
  while (gamerun == true) {
    std::cout << "> Enter the action you would like to perform:" << std::endl;
    std::cout << "> (to see the controls type \"help\")" << std::endl;
    std::cout << "<< ";
    getline(std::cin, gameAction);
    p.playerAction(gameAction, p);
    if (p.getPlayerAlive() == 0)
      gamerun = false;
  }
}

bool Game::getGameRun() {
  return gamerun;
}
