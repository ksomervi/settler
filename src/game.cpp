#include "game.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

game::game(int num_players, logger *l) : _gen(), _dist(1,6) {
  _log = l;
  player *p = NULL;

  for (int i=0; i<num_players; i++) {
    p = new player(i);
    l->debug("player " + std::to_string(p->id()) + " created");
    _players.push_back(p);
  }

  _board = new board(l);

  std::random_device rd;
  _gen.seed(rd());
}

void game::initialize() {

}

int game::roll_dice() {
  int rv = (_dist(_gen) + _dist(_gen)); 
  ++_hist[rv];
  return rv;
}

void game::quit() {
  _log->debug("quitting...");
  _log->debug("Dice roll histogram:");
  for (auto p : _hist) {
    _log->debug( std::to_string(p.first) + " : " + std::to_string(p.second) 
        + " : " + std::string(p.second/100, '*'));
      /*
    std::cout << p.first << " : " << p.second << " : " 
      << std::string(p.second/100, '*') << endl;
      */
  }
}

