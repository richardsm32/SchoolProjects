#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Inventory.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

/**
* @author Mathew Richards, Lorenzo Conrad
* @date 5 Mar 2019
* @brief Class for Player options within the game.
*/


class Player {
 public:
  /**
  * @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
  * @date 2019-03
  *  @brief Creates a new Player object.
  */
  Player();
  /**
  * @brief Prints the Player's room number,
  *  name, and inventory.
  */
  void playerInfo();
  /**
  * @brief Assigns the Player's
  * actions to different functions.
  * @param action The action that the
  * player should use.
  * @param &p Passby reference to player because changes
  * are made to the player object based on actions taken.
  */
  void playerAction(string, Player&);
  //action functions
  /**
  * @brief Action function to display the
  * help menu.
  */
  string playerHelp();
  /**
  * @brief Action function to use a Player's
  * item.
  * @param &p Passby reference to player, changes
  * are made to the players inventory.
  */
  void playerUse(Player&);
  /**
  * @brief Action function for a Player to
  * examine an item.
  * @param &p Passby reference to player,
  * player inventory needs to be accessed in order to be examined.
  */
  void playerExamine(Player&);
  /**
  * @brief Action function for a Player to
  * travel to the next logical game location.
  * @param &p Passby reference to player, changes
  * are made to the player location.
  */
  void playerTravel(Player&);
  /**
  * @brief Action function when a Player is
  * talking to an Npc.
  * @param &p Passby reference to player, different npcs you talk
  * to have different affects on the player object
  */
  void playerTalk(Player&);
  /**
  * @brief Action function for a Player giving
  * someone else an item.
  * @param sitem Item name that is given away by player
  */
  void playerGive(string);
  /**
  * @brief Action function for if a Player has
  * a teleport item, allow them to teleport.
  * @param &p Passby reference to player, changes need to be
  * made to the players location.
  */
  void playerTele(Player&);
  //setters and getters
  /**
  * @brief Setter for playerAlive int. <br>
  * Used to determine if the Player is
  * alive or not.
  * @param status The status of a players Aliveness.
  */
  void setPlayerAlive(int);
  /**
  * @brief Getter for playerAlive int. <br>
  * Used to determine if the Player is
  * alive or not.
  */
  int getPlayerAlive();
  /**
  * @brief Given the location number,
  * returns the string name of the location.
  * @param numloc Location number
  */
  string numberToLocation(int);
  /**
  * @brief Getter for playerLocation int. <br>
  * Used to determine the Player's location
  * within the game.
  */
  int getPlayerLocation();
  /**
  * @brief Setter for playerLocation int. <br>
  * Used to determine the Player's location
  * within the game.
  * @param loc New location traveling to.
  * @param &p Passby reference to Player, changes
  * are made to player stats.
  */
  string setPlayerLocation(int, Player&);
  /**
  * @brief Player is given an item<br>
  * @param item The item the user gets.
  */
  void playerGet(string);
  /**
  * @brief Searches a player's inventory for an item.
  * @param item The item you are searching for.
  */
  int searchPlayerInv(string);
  /**
  * @brief Setter for playerName string.
  * @param name String used for players name.
  */
  void setName(string);
  /**
  * @brief Getter for playerName string.
  */
  string getName();
  /**
  * @brief Allows a Player to examine the current room.
  * @param &p Passby reference to Player, changes are made to
  * player object stats (private data members).
  */
  string examineRoom(Player&);
  /**
  * @brief Method for saving a Player's current
  * instance of The Orb
  * @param filename The filename of for the save file
  * (default is playerName)
  * @param &p Passby reference to player, for quitting the game.
  */
  void save(string filename, Player&);
  /**
  * @brief Method for loading a Player's current
  * instance of The Orb
  * @param filename The filename of for the save file
  * (default is playerName)
  * @param &p Passyby reference to Player as player info
  * needs to be inputed into game
  */
  void load(string filename, Player&);
  /**
  * @brief Changes the input from the user to a string
  * to an int and catches if they are
  */
  int changePChoice();
  /**
  * @brief Is a function to change a private member called rankor test
  * @param ranctest Int required to pass a rankor test later in the game
  */
  void setRancorTest(int);
  /**
  * @brief Function to check the value of rankor test
  */
  int getRancorTest();

 private:
  Inventory playerInv;
  string playerName;
  int playerAlive;
  int playerLocation;
  int rancorTest;
};

#endif // CHARACTERS_H_INCLUDED
