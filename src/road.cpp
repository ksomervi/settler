#include "road.h"

road::road() {
  _has_town = false;
}

    
bool road::has_town() {
  //return (_town != NULL);
  return _has_town;
}

