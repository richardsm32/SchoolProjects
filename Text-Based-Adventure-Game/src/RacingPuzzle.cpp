/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Implementation of the Race Puzzle in The Orb
*/

#include "RacingPuzzle.h"
#include <unistd.h>
#include "Exceptions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;

RacingPuzzle::RacingPuzzle() {
}

int RacingPuzzle::Race() {
  unsigned int seed1;
  time_t start;
  int errorCount = 0;

  std::cout << "> This race will be a 30 seconds dash. "
            << "Use the number pad to enter the number that appears "
            << "then press [ENTER], but if you enter an incorrect number "
            << "more than 5 times you will crash!! "
            << "You must finish in less than 30 seconds!! "
            << std::endl << std::endl;
  std::cout << "> Press [ENTER] when you are ready to begin..." << std::endl;

  std::cin.get();  // require the enter key press before proceeding
  start = time(NULL);
  for (int i = 0; i < 25; i++) {
    int raceNum, inNum;
    usleep(50000);
    raceNum = rand_r(&seed1) % 10;
    std::cout << raceNum << std::endl;
    std::cin >> inNum;
    if (errorCount == 6) {
      std::cout << "> You crashed!!" << std::endl;
      break;
    }
    if (inNum != raceNum) {
      errorCount++;
      std::cout << "***" << std::endl;
    } else {
      std::cout << "*" << std::endl;
    }
  }
  if (errorCount < 6) {
    time_t finish;
    double seconds;
    finish = time(NULL);
    seconds = difftime(finish, start);
    std::cout << "> You took " << seconds << " seconds to finish the race!" <<
              std::endl;
    if (seconds < 31) {
      std::cout << "> GREAT JOB!!!!!" << std::endl;
      std::cout << "> YOU WIN!!!!" << std::endl;
      std::cin.ignore();
      return 1;
    } else {
      std::cout << "> You are too slow!! " << std::endl;
      std::cout << "> FAIL!!!!" << std::endl;
      std::cout << "> Press [ENTER] to retry" << std::endl;
      std::cin.ignore();
      std::cin.get();
      Race();
    }
  } else {
    std::cout << "> FAIL!!!!" << std::endl;
    sleep(3);
    std::cout << "> Press [ENTER] to retry" << std::endl;
    std::cin.ignore();
    std::cin.get();
    Race();
  }
  return 0;
}






