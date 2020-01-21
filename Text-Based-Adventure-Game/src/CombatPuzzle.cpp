/**
* @author Mathew Richards, Lorenzo Conrad, Ricky Bueckert
* @date 5 Mar 2019
* @brief Implementation of the Combat Puzzle portion of The Orb
*/

#include "CombatPuzzle.h"
#include <unistd.h>
#include "Exceptions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using std::string;
using std::vector;


CombatPuzzle::CombatPuzzle() {
}

void CombatPuzzle::Combat(Player& p) {
  unsigned int seed1, seed2, seed3, seed4;
  int playerHealth = 100, enemyHealth = 100;
  int turnNo = 0, dodge;
  string action;
  vector<int> enemyList {1, 1, 3, 1, 2, 5};
  std::cout << "> You hear the full-on battle scream of the mercenary as "
            << "they approach striking distance. They are wielding a tire iron "
            << "in each hand but look as if they have not slept in days, both "
            << "crazed and tired. Thankfully you have some fighting experience "
            << "from a simulator you use in your spare time. As they reach"
            << " your position you must choose your first move. " << std::endl;
  while (enemyHealth > 0) {
    int playerAction, enemyAction;
    std::cout << "********************" << std::endl;
    enemyAction = enemyList[turnNo];
    std::cout << ">> Player Health = " << playerHealth << " | Enemy "
              << "Health = " << enemyHealth << std::endl;
    std::cout << "> Your choices are: " << std::endl;
    std::cout << "1. Attack, 2. Defend, 3. Dodge, 4. Taunt " << std::endl;
    std::cout << "Choose!" << std::endl;
    std::cout << "< ";
    getline(std::cin, action);
    playerAction = stoi(action);
    // RULES FOR COMBAT
    if (playerAction == 1 && enemyAction == 1) {
      std::cout << "> Player and enemy attack!" << std::endl;
      playerHealth -= 15;
      enemyHealth -= 10;
    } else if (playerAction == 1 && enemyAction == 2) {
      std::cout << "> Player attacks, enemy defends successfully!"
                << std::endl;
    } else if (playerAction == 2 && enemyAction == 2) {
      std::cout << "> Player and enemy defend, nothing happens" << std::endl;
    } else if (playerAction == 2 && enemyAction == 1) {
      std::cout << "> Enemy attacks, player defends"
                << std::endl;
      dodge = rand_r(&seed4);
      if (dodge > 50) {
        std::cout << "You successfully block all damage!" << std::endl;

      } else {
        std::cout << "You suffer a small amount of damage!" << std::endl;
        playerHealth -= 5;
      }
    } else if (playerAction == 3 && enemyAction == 2) {
      std::cout << "> Player dodges and enemy defends, nothing happens"
                << std::endl;
    } else if (playerAction == 1 && enemyAction == 3) {
      dodge = rand_r(&seed1) % 100;
      if (dodge > 60) {
        std::cout << "> Enemy dodges successfully" << std::endl;
      } else {
        std::cout << "> Player attacks, enemy dodge failed" << std::endl;
        enemyHealth -= 10;
      }
    } else if (playerAction == 3 && enemyAction == 3) {
      std::cout << "> Both player and enemy dodge, no effect" << std::endl;
    } else if (playerAction == 3 && enemyAction == 1) {
      dodge = rand_r(&seed2) % 100;
      if (dodge > 50) {
        std::cout << "> Player dodges successfully" << std::endl;
        std::cout << "> You counter-attack for minor damage" << std::endl;
        enemyHealth -= 5;
      } else {
        std::cout << "> Enemy attacks, player dodge failed" << std::endl;
        playerHealth -= 15;
      }
    } else if (playerAction == 4 && enemyAction == 1) {
      std::cout << "> Player taunts but enemy attacks for bonus damage!!" <<
                std::endl;
      playerHealth -= 15;
    } else if (playerAction == 4 && enemyAction != 1) {
      string taunt0 = "\"Your mother was a hamster!!\"";
      string taunt1 = "\"Your father smells of elderberry!!\"";
      int tauntStyle = rand_r(&seed3) % 2;
      if (tauntStyle == 0) {
        std::cout << "> Player taunts with " << taunt0 << std::endl;
        std::cout << "> Critical Hit!! " << std::endl;
        enemyHealth -= 15;
      } else {
        std::cout << "> Player taunts with " << taunt1 << std::endl;
        std::cout << "> Critical Hit!! " << std::endl;
        enemyHealth -= 15;
      }
    } else if (playerAction == 1 && enemyAction == 5) {
      std::cout << "> The enemy is exhausted and you attack for bonus "
                << "damage!" << std::endl;
      enemyHealth -= 15;
    } else if ((playerAction == 2 || 3) && enemyAction == 5) {
      std::cout << "> The enemy is exhausted and fails to act, but your "
                << "action has no effect!" << std::endl;
    }


    if (playerHealth <= 0) {
      std::cout << ">> You expend the final ounce of your energy to no "
                << "avail, as the mercenary stabs the tire iron through "
                << "your chest for a killing blow. You are dead.";
      p.setPlayerAlive(0);
      return;
    }
    std::cout << std::endl;
    turnNo++;
    if (turnNo > 5)
      turnNo = 0;
  }

  std::cout << ">> You swing the plank with your might and deliver the final "
            << " blow to the mercenary! They give one last breath and fall "
            << " to the ground. You live to fight another day! " << std::endl;
  return;
}
