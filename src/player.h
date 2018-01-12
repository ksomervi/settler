#ifndef SETTLER_PLAYER_H
#define SETTLER_PLAYER_H

#include "logger.h"
#include "resource.h"
//#include "town.h"

#include <map>
using std::map;

#include <vector>
using std::vector;

class player {
  private:
    logger *_log;
    int _id;
    int _score;
    map<product, int> _resources;

  public:

    player(int, logger* =NULL);
    
    void initialize();

    int id();
    void id(int);

    int add_resource(product, int =1);
    bool spend_resource(product, int =1);
    void dump_resources();
    int score();
    void score(int);

};
#endif //!define(SETTLER_PLAYER_H)

