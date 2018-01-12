#ifndef SETTLER_GAME_H
#define SETTLER_GAME_H

#include <map>
using std::map;

#include <random>
using std::random_device;

#include <vector>
using std::vector;

#include "board.h"
#include "logger.h"
#include "player.h"

class game {
  private:
    logger *_log;
    vector<player*> _players;
    board *_board;
    int _res_key;
    int _cur_player;

    std::mt19937 _gen;
    std::uniform_int_distribution<> _dist;
    map<int, int> _hist;

  public:

    game(int, logger* =NULL);
    
    void initialize();

    int roll_dice();
    void take_turn();
    void quit(bool =false);

    void dump_board();

};
#endif //!define(SETTLER_GAME_H)

