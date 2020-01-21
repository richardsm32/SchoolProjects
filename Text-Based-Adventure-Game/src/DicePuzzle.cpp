/**
* @author Mathew Richards, Lorenzo Conrad, Ricky Bueckert
* @date 5 Mar 2019
* @brief Implementation of the Dice puzzle in "The Orb"
*/
#include "DicePuzzle.h"
#include <stdlib.h>
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <ctime>

using std::string;


DicePuzzle::DicePuzzle() {
}

int DicePuzzle::playPuzzle() {
  unsigned int seed1, seed2, seed3;
  srand(time(NULL));
  string dummyVar;
  string userChoice = "yes";
  int gameresult = 0;

  while (userChoice == "yes") {
    int Die1 = rand_r(&seed1) % 21;
    int Die2 = rand_r(&seed2) % 21;
    int Die3 = rand_r(&seed3) % 21;
    std::cout << "Press ENTER to roll the dice." << std::endl;
    std::cout << "< ";
    getline(std::cin, dummyVar);
    std::cout << "The dice values are: " << Die1 << " , " << Die2 << " , "
              << Die3 <<std::endl;
    if (Die1 == 6 && Die2 == 7 && Die3 == 2) {
      std::cout << "You've done it!!" << std::endl;
      gameresult = 1;
    } else {
      std::cout << "> Those are not the sacred numbers of THE ORB"
                << std::endl;
    }
    std::cout << "Do you want to roll again? (type \"yes\" to roll again)"
              << std::endl << "(any other key will decline)" << std::endl;
    std::cout << "< ";
    getline(std::cin, userChoice);
  }
  return gameresult;
}

