
#include <iostream>
using namespace std;

#include "player.h"
#include "town.h"

int main() {
  logger * l = new logger();
  player * p = new player(1, l);
  town * t = new town(p, l);
  int errors = 0;
  town::level lvl = t->development_level();

  //Test 1: initial development level
  if (lvl != town::village) {
    errors++;
    l->error("incorrect development level");
    l->error("expected " + std::to_string(town::village) 
      + "but found " + std::to_string(lvl));
  }

  cout << "development level: " << t->development_level() << endl;
  cout << "upgrading town ..." << endl;
  t->upgrade();

  lvl = t->development_level();
  cout << "development level: " << t->development_level() << endl;

  //Test 2: upgraded (city) development level
  if (t->development_level() != town::city) {
    errors++;
    l->error("incorrect development level");
    l->error("expected " + std::to_string(town::city) 
      + "but found " + std::to_string(lvl));
  }

  if (errors > 0) {
    l->error("Failed tests: " + std::to_string(errors));
  }
  else {
    l->debug("All tests passed");
  }
}//end main

