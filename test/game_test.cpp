#include "logger.h"
#include "game.h"

using std::cout;
using std::endl;

int main() {
  logger *l = new logger();
  game * g = new game(3, l);
  g->initialize();

  g->print_scores();
  g->dump_board();

  g->take_turn();
  g->take_turn();
  g->take_turn();
  g->take_turn();
  g->take_turn();
  g->take_turn();


  for (int i=0; i<10000; i++) {
    g->roll_dice();
  }

  g->quit(true);

}
