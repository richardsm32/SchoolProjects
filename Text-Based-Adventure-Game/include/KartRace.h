/**
* @author Mathew Richards, Ricky Bueckert, Lorenzo Conrad
* @date 2019-03
* @brief Derived class of Locations to represent the "KartRace"
* location.
*/

#ifndef INCLUDE_KARTRACE_H
#define INCLUDE_KARTRACE_H

class KartRace {
 public:
  /**
  * @brief Default constructor to create a KartRace
  * object.
  */
  KartRace();
  /**
  @brief Progresses user to the pre-race section
  * of the KartRace location.
  */
  void L_prerace();
  /**
  @brief Progresses user to the actual race section
  * of the KartRace location.
  */
  void L_race();
  /**
  @brief Progresses user to the post-race section
  * of the KartRace location.
  */
  void L_postRace();
};
#endif
