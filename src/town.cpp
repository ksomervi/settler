#include "town.h"

town::town() {
  _lvl = village;
}

#if defined(SETTLER_PLAYER_H)
town::town(player* p, logger *l) {
//town::town(player* p) {//, logger *l) {
  _p = p;
  _lvl = village;
//  _log = l;

  /*
  if (l) {
    _log = l;
  }
  else {
    _log = new logger();
  }
  */
}
#endif //defined(SETTLER_PLAYER_H)

void town::upgrade() {
  _lvl = city;
}//end upgrade()


town::level town::development_level() {
  return _lvl;
}//end development_level()

#if defined(SETTLER_PLAYER_H)
player* town::owner() {
  return _p;
}
#endif

