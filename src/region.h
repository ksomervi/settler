#ifndef SETTLER_REGION_H
#define SETTLER_REGION_H

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "logger.h"
#include "resource.h"

class region {
  private:
    product _prod;
    bool _robber;
    bool _port;
    int _sel; //value: 2..12
    int _id;

    map<int, int> _neighbors; //map border (1..6) to neighbor (1..18) regions

  public:

    region();
    int id();
    void id(int);

    bool robber_hideout();
    void robber_hideout(bool);

    int selector();
    void selector(int);

    void resource_type(product);
    product resource_type();

    /*! Adds neighbor to the list.
     */
    bool add_neighbor(int, int);

    bool has_neighbor(const int);

};

#endif //!define(SETTLER_REGION_H)

