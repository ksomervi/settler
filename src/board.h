#ifndef SETTLER_BOARD_H
#define SETTLER_BOARD_H

#include "logger.h"
#include "region.h"
//#include "road.h"
//#include "town.h"

#include <vector>
using std::vector;


class board {
  private:
    logger *_log;
    vector<region*> _regions;
    //vector<border*> _borders;
    //vector<road*> _roads;

  public:
    typedef vector<region*> region_set;
    const int nregions = 18;

    board(logger* =NULL);

    bool add_neighbor(region *, int);

    void initialize();

    bool build_town();
    bool build_road();

    void dump_board();
    void collect_resources(int);
};
#endif //!define(SETTLER_BOARD_H)

