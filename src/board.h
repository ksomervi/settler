#ifndef SETTLER_BOARD_H
#define SETTLER_BOARD_H

#include "logger.h"
#include "region.h"
//#include "road.h"
//#include "town.h"

#include <vector>
using std::vector;

#include <map>
using std::map;

class board {
  private:
    logger *_log;
    vector<region*> _regions;
    //map<int, vector<int> > _neighbors;
    //vector<road*> _roads;
    map<int, vector<region*> > _fortune;

  public:
    //typedef vector<region*> region_set;
    const int nregions = 18;

    board(logger* =NULL);

    bool add_neighbor(region *, int);
    //bool is_neighbor(region *, int);

    bool build_town();
    bool build_road();

    void collect_resources(int);
    void dump_board();

    void initialize(bool =false);
    void initialize_default();
    void initialize_random();
};
#endif //!define(SETTLER_BOARD_H)

