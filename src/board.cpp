#include "board.h"

#include <string>
using std::string;

board::board(logger *l) {
  _log = l;

  // Allocate 18 regions
  for (int i =0; i<=18; i++) {
    region *r = new region();
    r->id(i);
    switch(i) {
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
    }//end switch(i)

    switch (i) {
      case(17):
        r->selector(2);
        break;

      case(1): case(15):
        r->selector(3);
        break;

      case(4): case(9):
        r->selector(4);
        break;

      case(3): case(18):
        r->selector(5);
        break;

      case(2): case(16):
        r->selector(6);
        break;

      case(0):
        //r->selector(0);
        break;

      case(8): case(14):
        r->selector(8);
        break;

      case(6): case(12):
        r->selector(9);
        break;

      case(7): case(13):
        r->selector(10);
        break;

      case(5): case(10):
        r->selector(11);
        break;

      case(11):
        r->selector(12);
        break;
    }//end switch(i)

    _regions.push_back(r);
  }
    
  _log->debug("regions allocated");

  // Set the region type
  // Set the resource rate (dice value: 2 - 12)
  // Set the neighbors
  //
  // Locate initial towns, 1 per player

}

void board::dump_board() {
  for (auto r: _regions) {
    _log->debug("region: " + std::to_string(r->id()) + " resource: " 
        + r->resource_name() + " selector: " + std::to_string(r->selector()));
  }

}

void board::initialize() {

}

bool board::build_town() {
  return true;
}

bool board::build_road() {
  return true;
}

void board::collect_resources(int) {

}
