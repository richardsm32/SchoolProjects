/**
@author Mathew Richards, Lorenzo Conrad, Ricky Bueckert
@date 5 Mar 2019
@brief Implementation of the Dice puzzle in "The Orb"
*/

#ifndef INCLUDE_DICEPUZZLE_H
#define INCLUDE_DICEPUZZLE_H

#include <stdlib.h>

class DicePuzzle {
 public:
  /**
  * @brief Default constructor for the Dice Puzzle
  */
  DicePuzzle();
  /**
  * @brief Starts the Dice Puzzle minigame.
  */
  int playPuzzle();
};
#endif
