#include "player.h"

player::player(int id, logger *l) {

  _id = id;
  _score = 0;
  //_towns.clear();

  _log = l;

}

void player::initialize() {
  _resources[wood] = 0;
  _resources[brick] = 0;
  _resources[ore] = 0;
  _resources[cattle] = 0;
  _resources[wheat] = 0;
}

int player::id() {
  return _id;
}

void player::id(int id) {
  _id = id;
}

int player::add_resource(product p, int amount) {
  _resources[p] += amount;
  return _resources[p];
}//end add_resource()


bool player::spend_resource(product p, int amount) {
  if (_resources[p] < amount) {
    return false;
  }
  _resources[p] -= amount;
  return true;
}//end add_resource()

void player::dump_resources() {
  for (auto& r: _resources) {
    _log->debug(std::to_string(r.second) + " units of " + resource_name(r.first));
  }
}

int player::score() {
  return _score;
}

void player::score(int score) {
  _score = score;
}

