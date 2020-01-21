/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Implements the NPC talking lines and statements.
* Calls other functions as needed to progress the game.
* (i.e. adding an item to inventory during conversation, etc.)
*/

#ifndef INCLUDE_NPC_H
#define INCLUDE_NPC_H
#include "Player.h"

class Npc {
 public:
  /**
  * @brief Default constructor to create an NPC object.
  */
  Npc();
  /**
  * @brief Method implementing NPC Gertrude's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Gertrude(Player&);
  /**
  * @brief Method implementing NPC Bartender's actions <br>
  * No parameters as this NPC does not change the Player's
  * actions.
  */
  void Bartender();
  /**
  * @brief Method implementing NPC Simon's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Simon(Player&);
  /**
  * @brief Method implementing NPC Roy's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Roy(Player&);
  /**
  * @brief Method implementing NPC Edmund's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Edmund(Player&);
  /**
  * @brief Method implementing NPC OutpostLeader's
  * actions <br>
  * No parameters as this NPC does not change the Player's
  * actions.
  */
  void OutpostLeader(Player&);
  /**
  * @brief Method implementing NPC Drifter's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Drifter(Player&);
  /**
  * @brief Method implementing NPC JamJam's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void JamJam(Player&);
  /**
  * @brief Method implementing NPC Java's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Java(Player&);
  /**
  * @brief Method implementing NPC Snuggler's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Snuggler(Player&);
  /**
  * @brief Method implementing NPC Ackbari's actions
  * @param &p Passby reference for Player. Performs
  * an action on the Player - changes inventory, changes
  * life status, etc.
  */
  void Ackbari(Player&);
  /**
  * @brief Method implementing NPC Garfield's actions <br>
  * @param &p Passby reference for Player. An item is gained
  * and put in players inventory
  */
  void Garfield(Player&);
  /**
  * @brief Method changing the choice from a string to an
  * int as well as catching invalid input and asking the
  * player again for new input.
  */
  int changeChoice();
};
#endif
