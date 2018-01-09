#include "player.h"

player::player(int id, logger *l) {

  _id = id;
  _score = 0;
  //_towns.clear();

  _log = l;

}

void player::initialize() {
}
int player::id() {
  return _id;
}

void player::id(int id) {
  _id = id;
}


