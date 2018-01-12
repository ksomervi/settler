#include "game.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

using std::to_string;

game::game(int num_players, logger *l) : _gen(), _dist(1,6) {
  _log = l;
  player *p = NULL;

  for (int i=0; i<num_players; i++) {
    p = new player(i);
    l->debug("player " + std::to_string(p->id()) + " created");
    _players.push_back(p);
  }

  _cur_player = 0;

  _board = NULL;

  std::random_device rd;
  _gen.seed(rd());
}

void game::initialize() {
  _board = new board(_log);
  _board->initialize();
}

void game::dump_board() {
  _board->dump_board();
}

void game::take_turn() {
  _log->debug(string(__FUNCTION__) + "()");
  _log->debug("player: " + to_string(_cur_player));
  // roll the dice
  _res_key = roll_dice();
  _log->debug("resource key: " + std::to_string(_res_key));

  // collect resources from regions
  _board->collect_resources(_res_key);

  // apply collections to players
  // players exchange resources
  // players build
  //
  _cur_player = (_cur_player + 1) % _players.size();
}//end take_turn()
  
int game::roll_dice() {
  int rv = (_dist(_gen) + _dist(_gen)); 
  ++_hist[rv];
  return rv;
}

void game::quit(bool dump) {
  _log->debug("quitting...");
  if (dump) {
    _log->debug("Dice roll histogram:");
    for (auto p : _hist) {
      _log->debug( std::to_string(p.first) + " : " + std::to_string(p.second) 
          + " : " + std::string(p.second/100, '*'));
    }
  }
}

