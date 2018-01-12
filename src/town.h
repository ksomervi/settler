#ifndef SETTLER_TOWN_H
#define SETTLER_TOWN_H

//#include "logger.h"
#include "player.h"

//#include <vector>
//using std::vector;

class town {
  public:
    enum level { village, city };

  private:
    level _lvl;
#if defined(SETTLER_PLAYER_H)
    player *_p;
#endif
    logger *_log;
    //vector<int> _regions; // holds id of adjacent regions for resource 
                          // collection

  public:
    town();

    void upgrade();
    level development_level(); 
    //void regions (int, int, int);
#if defined(SETTLER_PLAYER_H)
    town(player*, logger* =NULL);
    player* owner();
#endif

};//end class town
#endif //!define(SETTLER_TOWN_H)

