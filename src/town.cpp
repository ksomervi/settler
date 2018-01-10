
#include "town.h"

town::town(player* p, logger *l) {
  _p = p;

  if (l) {
    _log = l;
  }
  else {
    _log = new logger();
  }

}

void town::upgrade() {
  _lvl = town::city;
}


town::level town::development_level();  {
  return _lvl;
    
}
