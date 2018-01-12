#ifndef SETTLER_RESOURCE_H
#define SETTLER_RESOURCE_H

#include <string>
using std::string;

    
enum product {none, wood, brick, ore, cattle, wheat};

string resource_name(const product&);

#if 0
class resource {
  public:
    enum product {none, wood, brick, ore, cattle, wheat};

  private:
    product _prod;

    resource();
  public:

    resource(product);

    product type();
    string name();
};
#endif
    
#endif //!define(SETTLER_RESOURCE_H)

