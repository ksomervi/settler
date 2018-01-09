#include "region.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

region::region() {
  _id = 0;
  _prod = none;
  _port = false;
  _robber = false;
  _sel = 0;
}

string region::resource_name() {
  string rv;
  switch (_prod) {
    case(wood):
      rv = "WOOD";
      break;

    case(brick):
      rv = "BRICK";
      break;

    case(ore):
      rv = "ORE";
      break;

    case(cattle):
      rv = "CATTLE";
      break;

    case(wheat):
      rv = "WHEAT";
      break;

    default:
      rv = "NONE";
      break;
  }//end switch(_prod)

  return rv;

}

void region::resource_type(product p) {
  _prod = p;
}

region::product region::resource_type() {
  return _prod;
}

//Perhaps move this to the board level.
bool region::add_neighbor(int rid, int border) {
  if (border < 0 or border > 6) {
    //_log->error("invalid border")
    return false;
  }
  
  if (rid < 0 or rid > 18) {
    //_log->error("invalid region")
    return false;
  }

  if (has_neighbor(rid) == false) {
    cerr << "rid(" << rid << ") already a neighbor" << endl;
    return false;
  }

  _neighbors[border] = rid;

  return true;
}

bool region::has_neighbor(const int rid) {
  for (auto& p: _neighbors) {
    if (rid == p.second) {
      return p.first;
    }
  }
  return false;

}


int region::id() {
  return _id;
}

void region::id(int i) {
  _id = i;
}

bool region::robber_hideout() {
  return _robber;
}

void region::robber_hideout(bool r) {
  _robber = r;
}

int region::selector() {
  return _sel;
}

void region::selector(int s) {
  _sel = s;
}


