#include "board.h"
#include "resource.h"

#include <string>
using std::string;
using std::to_string;

board::board(logger *l) {
  _log = l;

  // Allocate 18 regions
  for (int i =0; i<=18; i++) {
    region *r = new region();
    r->id(i);
    _regions.push_back(r);
  }

  _log->debug("regions allocated");
}

void board::dump_board() {
  for (auto r: _regions) {
    _log->debug("region: " + std::to_string(r->id())
        + " resource: " + resource_name(r->resource_type())
        + " selector: " + std::to_string(r->selector()));

    string m = string("neighbors:");
    for (auto n: _neighbors[r->id()]) {
      m += " " + to_string(n);
    }//end for (auto n: _neighbors[])
    _log->debug(m);
  }//end for (auto r: _regions)
}//end dump_board()

void board::initialize(bool rnd) {
  if (rnd) {
    initialize_random();
  }
  else {
    initialize_default();
  }
  _initialize_neighbors();
}

void board::_make_neighbors(int r1, int r2) {
  _log->debug(string(__FUNCTION__) + ": " + to_string(r1) + "-" + to_string(r2));
  auto m = _neighbors.find(r1);
  if (m != _neighbors.end()) {
    _log->debug("found r1(" + to_string(r1) + "): searching neighbors");
    for (auto& n: _neighbors[r1]) {
      if (n == r2) {
        _log->debug("found neighbor r2(" + to_string(r2) + "): not adding neighbor");
        return;
      }
    }//end for (auto& n: _neighbors[r1])
    _log->debug("did not find r2(" + to_string(r2) + "): adding neighbor");
  }
  else {
    _log->debug("did not find r1(" + to_string(r1) + "): adding first neighbor");
  }//end if (m != _neighbors.end())
  _neighbors[r1].push_back(r2);
}//end _make_neighbor(int r1, int r2)

int board::_ring_max(int ring) {
  if (ring > 1) {
    return _ring_max(ring-1) + (ring * 6);
  }
  return (ring * 6);
}

void board::_initialize_neighbors() {
  int ring = 1;
  //int rgn=0;

  //do ring 1
  int ring_max = _ring_max(ring);
  for (int i=0; i<ring_max; i++) {
    int r_id = i + 1;
    // Add region 0
    _make_neighbors(r_id, 0);
    _make_neighbors(0, r_id);

    // Add i-1, i.e., (i+5)%ring_max
    int pre = ((i+5) % ring_max) +1;
    _make_neighbors(r_id, pre);
    _make_neighbors(pre, r_id);

    //Add i+1, i.e., (i+1)%ring_max
    int post = ((i+1) % ring_max) +1;
    _make_neighbors(r_id, post);
    _make_neighbors(post, r_id);

    // Add neighbors from next ring
    // The next radial neighbor is 2*r_id + 6
    int nnr = 2*r_id + 6;
    _make_neighbors(r_id, nnr);
    _make_neighbors(nnr, r_id);

    // need to update ring_max for next ring

    // Add nnr-1 (nnr > 1)
    pre = nnr-1;
    _make_neighbors(r_id, pre);
    _make_neighbors(pre, r_id);

    //Add i+1, i.e., (i+1)%ring_max
    //FIXME: doesn't wrap correctly
    //Range is 7..18, so let's reset to 0-based counting
    int k = nnr-7;
    //post = ((k+1) % _ring_max(ring+1)) +7;
    post = ((k+1) % ((ring+1)*6)) +7;
    _log->debug("nnr=" + to_string(nnr) + " k=" + to_string(k)
        + " post=" + to_string(post));
    _make_neighbors(r_id, post);
    _make_neighbors(post, r_id);
  }//end for (int i=0; i<ring_max; i++)
}

void board::initialize_random() {
  //Not implemented
  _log->debug(string(__FUNCTION__) + "(): not implemented");
  initialize_default();
}

void board::initialize_default() {
  _log->debug(string(__FUNCTION__) + "()");

  // Set the region type
  for (auto r: _regions) {
    switch(r->id()) {
      case (1): case(9): case(15):
        r->resource_type(brick);
        break;

      case(2): case(12): case(16): case(18):
        r->resource_type(wood);
        break;

      case(3): case(6): case(8):
        r->resource_type(ore);
        break;

      case(4): case(11): case(13): case(17):
        r->resource_type(cattle);
        break;

      case(5): case(7): case(10): case(14):
        r->resource_type(wheat);
        break;

      default:
        r->resource_type(none);
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
    _log->debug("collecting resource (" + resource_name(r->resource_type()) + ") from region "
        + std::to_string(r->id()));
    // does the region have any towns
    // add points to any players

  }
}//collect_resources()
