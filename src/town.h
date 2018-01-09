#ifndef SETTLER_TOWN_H
#define SETTLER_TOWN_H

#include "logger.h"
#include "player.h"
#include "region.h"

#include <vector>
using std::vector;

class town {
  private:
    vector<road *>;// max roads is 3
    player *_p;


  public:
    enum town_class = { town, city };
    //typedef enum _town_class town_class;

    town();

};
#endif //!define(SETTLER_TOWN_H)

