#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* @brief Exception for an invalid item is passed to a constructor or method.
* @param errMessage An error message.
*/

class item_error: public std::runtime_error {
 public:
  explicit item_error(const char* errMessage) :
    std::runtime_error(errMessage) {}
};

/**
* @brief Exception for when an invalid location is passed
* to a constructor or method.
* @param errMessage An error message.
*/

class location_error: public std::runtime_error {
 public:
  explicit location_error(const char* errMessage) :
    std::runtime_error(errMessage) {}
};

/**
* @brief Exception for when an invalid action is passed
* to a constructor or method.
* @param errMessage An error message.
*/

class action_error: public std::runtime_error {
 public:
  explicit action_error(const char* errMessage) :
    std::runtime_error(errMessage) {}
};






#endif // EXCEPTIONS_H_INCLUDED
