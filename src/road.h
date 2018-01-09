#ifndef SETTLER_ROAD_H
#define SETTLER_ROAD_H

#include <vector>
using std::vector;

#include <map>
using std::map;


class road {
  private:
    //map<int, int>region * _neighbors[2];
    map<int, int> _bordered;
    bool _has_town;

  public:
    road();

    bool has_town();

};

#endif //!define(SETTLER_ROAD_H)

