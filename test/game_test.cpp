#include "logger.h"
#include "game.h"

using std::cout;
using std::endl;

int main() {
  logger *l = new logger();
  game * g = new game(3, l);

  for (int i=0; i<10000; i++) {
    g->roll_dice();
  }

  g->quit();

}
