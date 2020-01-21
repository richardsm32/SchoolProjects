/**
* @author Mathew Richards
* @date 2019-09
* @brief Header for the Cards class
*/

#ifndef INCLUDE_CARDS_H
#define INCLUDE_CARDS_H

#include <vector>
#include <string>

enum Suit {HEARTS, SPADES, DIAMONDS, CLUBS, NOTHING};

class Cards {
 public:
    int value; //ie. number or face-card symbol
    Suit suit; //represented by a char in an enum
    Cards();
    Cards(int v, Suit s);
    virtual ~Cards();
    virtual int getValue();
    virtual void setValue(int a);
    virtual Suit getSuit();

 private:
};


#endif

