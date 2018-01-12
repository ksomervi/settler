#include <iostream>
using std::cerr;
using std::endl;
using std::to_string;

#include "player.h"

int main() {
  logger *l = new logger();
  player *p = new player(1, l);

  bool sts = false;
  int rv = 0;
  int errors = 0;

  p->dump_resources();
  rv = p->add_resource(wood);
  l->debug("returned " + to_string(rv));
  p->dump_resources();

  if (p->spend_resource(ore)) {
    l->error("Should not be able to spend " + to_string(ore));
    errors++;
  }

  if (errors) {
    l->error("Failed tests: " + to_string(errors));
  }
  else {
    l->debug("All tests passed");
  }
}//end main()
