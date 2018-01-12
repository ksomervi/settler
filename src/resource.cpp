#include "resource.h"

string resource_name(const product &p) {
  string rv;
  switch (p) {
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
  }//end switch(p)

  return rv;

}

