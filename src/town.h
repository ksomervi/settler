#ifndef SETTLER_TOWN_H
#define SETTLER_TOWN_H

#include "logger.h"
#include "player.h"

#include <vector>
using std::vector;

class town {
  private:
    level _lvl;
    player *_p;
    //vector<int> _regions; // holds id of adjacent regions for resource 
                          // collection

  public:
    enum level = { town, city };

    town(player*, logger* =NULL);

    void upgrade();
    level development_level(); 
    //void regions (int, int, int);

};
#endif //!define(SETTLER_TOWN_H)

