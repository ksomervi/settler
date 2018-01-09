
#include "../logger.h"

using std::cout;
using std::endl;

int main() {

  logger *l = new logger();

  cout << "log threshold: " << l->threshold() << endl;
  l->debug("hello");
  l->error("hello");
  l->print("hello");

  l->threshold(logger::dbg);
  cout << "log threshold: " << l->threshold() << endl;

  l->debug("hello");
  l->error("hello");
  l->print("hello");
}//end main()


