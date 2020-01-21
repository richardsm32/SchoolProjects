#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <string>
#include <vector>
using std::string;
using std::vector;

/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Manages a Player's inventory within the game.
*/

class Inventory {
 public:
  /**
  * @brief Creates a vector
  * which stores all of the inventory items that
  * a user can have.
  */
  Inventory();
  /**
  * @brief Searches a player's inventory
  * for a specified item.
  * @param sitem The item to search for.
  * @return Either a 1 or 0 depending on
  * if the item is in the user's inventory
  * or not.
  */
  int searchInventory(string sitem);
  /**
  * @brief Adds a specified item to
  * a player's inventory.
  * @param gitem The item to add to inventory.
  */
  void addItem(string gitem);
  /**
  * @brief Given a numerical value, findItem
  * returns the item's name
  * @param index The location of the item
  * in the array.
  * @return The item's name, a string
  */
  string findItem(int index);
  /**
  * @brief Checks if you have the first password.
  * @return The first password, or a "you don't have
  * the password" message.
  */
  string password1();
  /**
  * @brief Checks if you have the second password.
  * @return The second password, or a "you don't have
  * the password" message.
  */
  string password2();
  /**
  * @brief Checks if you have the third password.
  * @return The third password, or a "you don't have
  * the password" message.
  */
  string password3();
  /**
  * @brief Test function for inventory. Allows checking
  * if the Player's starting inventory is empty.
  * @param index The index of the inventory vector.
  */
  int getInven(int index);
  /**
  * @brief Subtracts an item from the inventory when it it
  * is traded
  * @param sitem The name of the inventory item.
  */
  void subItem(string sitem);
  /**
  * @brief Function to return the string outputted when an
  * item is examined
  * @param eitem The name of the inventory item.
  */
  string examineInv(string eitem);
  /**
  * @brief Function containing the contents in a string format
  * of what the pamphlet item contains
  */
  string examinePamph();
  /**
  * @brief Function returns the inventory vector itself
  * to be filled in the load phase
  */
  vector<int> & getAll() {
    return inventory;
  }

 private:
  vector<int> inventory;
  string sitem, gitem, eitem;
  string pass1, pass2, pass3;
};

#endif // CHARACTERS_H_INCLUDED
