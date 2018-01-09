#ifndef SETTLER_PLAYER_H
#define SETTLER_PLAYER_H

#include "logger.h"
//#include "town.h"

#include <vector>
using std::vector;

class player {
  private:
    logger *_log;
    int _id;
    int _score;
    //vector<towns*> _towns;

  public:

    player(int, logger* =NULL);
    
    void initialize();

    int id();
    void id(int);

};
#endif //!define(SETTLER_PLAYER_H)

