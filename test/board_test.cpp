#include <iostream>

using namespace std;

#include "board.h"
#include "logger.h"

int main() {
  logger *l = new logger();
  l->debug("logger started...");
  board *b = new board(l);

  b->dump_board();

}
