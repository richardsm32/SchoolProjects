/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Implementation of the Combat Puzzle in The Orb
*/

#ifndef INCLUDE_COMBATPUZZLE_H
#define INCLUDE_COMBATPUZZLE_H
#include "Player.h"

class CombatPuzzle {
 public:
  /**
  * @brief Default constructor to create
  * a CombatPuzzle object.
  */
  CombatPuzzle();
  /**
  * @brief CombatPuzzle minigame implementation
  * @param &p Passby reference for Player
  * object.
  */
  void Combat(Player&);
};


#endif

