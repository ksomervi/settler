#include "board.h"
#include "resource.h"

#include <string>
using std::string;

board::board(logger *l) {
  _log = l;

  // Allocate 18 regions
  // Set the region type
  for (int i =0; i<=18; i++) {
    region *r = new region();
    r->id(i);
    _regions.push_back(r);
  }
    
  _log->debug("regions allocated");
}

void board::dump_board() {
  for (auto r: _regions) {
    _log->debug("region: " + std::to_string(r->id()) + " resource: " 
        + r->resource_name() + " selector: " + std::to_string(r->selector()));
  }

}//end dump_board()

void board::initialize(bool rnd) {
  if (rnd) {
    initialize_random();
  }
  else {
    initialize_default();
  }
}

void board::initialize_random() {
  //Not implemented
  _log->debug(string(__FUNCTION__) + "(): not implemented");
  initialize_default();
}

void board::initialize_default() {
  _log->debug(string(__FUNCTION__) + "()");
  for (auto r: _regions) {
    switch(r->id()) {
      case (1): case(9): case(15):
        r->resource_type(region::brick);
        break;

      case(2): case(12): case(16): case(18):
        r->resource_type(region::wood);
        break;

      case(3): case(6): case(8):
        r->resource_type(region::ore);
        break;

      case(4): case(11): case(13): case(17):
        r->resource_type(region::cattle);
        break;

      case(5): case(7): case(10): case(14):
        r->resource_type(region::wheat);
        break;

      default:
        r->resource_type(region::none);
        r->robber_hideout(true);
    }//end switch(r->id())

    // Set the resource rate (dice value: 2 - 12)
    switch (r->id()) {
      case(17):
        _fortune[2].push_back(r);
        r->selector(2);
        break;

      case(1): case(15):
        _fortune[3].push_back(r);
        r->selector(3);
        break;

      case(4): case(9):
        _fortune[4].push_back(r);
        r->selector(4);
        break;

      case(3): case(18):
        _fortune[5].push_back(r);
        r->selector(5);
        break;

      case(2): case(16):
        _fortune[6].push_back(r);
        r->selector(6);
        break;

      case(0):
        //r->selector(0);
        break;

      case(8): case(14):
        _fortune[8].push_back(r);
        r->selector(8);
        break;

      case(6): case(12):
        _fortune[9].push_back(r);
        r->selector(9);
        break;

      case(7): case(13):
        _fortune[10].push_back(r);
        r->selector(10);
        break;

      case(5): case(10):
        _fortune[11].push_back(r);
        r->selector(11);
        break;

      case(11):
        _fortune[12].push_back(r);
        r->selector(12);
        break;
    }//end switch(r->id())

  }//end for (auto r: _regions)

  // Set the neighbors
  //
  // Locate initial towns, 1 per player
}

bool board::build_town() {
  return true;
}

bool board::build_road() {
  return true;
}

void board::collect_resources(int k) {
  _log->debug(string(__FUNCTION__) + "()");

  for (auto r: _fortune[k]) {
    _log->debug("collecting resource (" + r->resource_name() + ") from region "
        + std::to_string(r->id())); 
    // does the region have any towns
    // add points to any players

  }
}//collect_resources()
