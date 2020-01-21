/**
* @author Mathew Richards
* @date 2019-10
* @brief Implementation of the Cards class
*/

#include "Cards.h"
//#include "Exceptions.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

Cards::Cards() {
    value = 0;
    suit = NOTHING;
}

Cards::Cards(int v, Suit s) {
    value = v;
    suit = s;
}

Cards::~Cards() {
    //destructor
}

int Cards::getValue() {
    return value;
}

void Cards::setValue(int a) {
    value = a;
}

Suit Cards::getSuit() {
    return suit;
}
