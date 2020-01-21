#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "OldMaid.h"

using namespace std;

int main()
{
    OldMaidUI u;
    Deck d;
    Hand h;
    OldMaid o;
    int players;
    players = o.numberOfPlayers(u);
    o.game(players, 0, &u, &d, &h);
    return 0;
}
