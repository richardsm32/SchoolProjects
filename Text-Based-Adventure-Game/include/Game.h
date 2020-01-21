#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H
#include "Exceptions.h"
#include "Player.h"
#include "Npc.h"
#include <iostream>
#include <string>
#include <fstream>
using std::string;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief "General UI for the game, allows users to start
* and stop the game, etc"
*/


class Game {
 public:
  /**
  * @brief Game constructor. Creates a new
  * instance of the game.
  */
  Game();
  /**
  * @brief The start menu for the game.
  */
  void startMenu();
  /**
  * @brief Runs the game.
  * @param &p A Player object - the player of the game.
  * and used for determining when to end game loop upon death
  * @param gamerun Determines whether the game is running or not
  */
  void runGame(bool, Player&);
  /**
  * @brief Gets the game running status.
  */
  bool getGameRun();

 private:
  string gameAction;
  bool gamerun;
};
#endif
