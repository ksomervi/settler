#include "logger.h"

#include <iostream>
//using std::cerr;
using std::endl;
using std::ostream;


logger::logger() {
  _threshold = note;  
  log = &std::cerr;
}

logger::logger(string f) {

}

void logger::error(string m) {
  *log << "ERROR: " << m << endl;
}

void logger::debug(string m) {
  if (_threshold <= dbg) {
    *log << "DEBUG: " << m << endl;
  }
}

void logger::print(string m) {
  if (_threshold == note) {
    *log << "NOTE: " << m << endl;
  }

}

void logger::threshold(loglevel l) {
  _threshold = l;
  if (_threshold == err) {
    *log << "Threshold: err" << endl;
  }
  else if (_threshold == dbg) {
    *log << "Threshold: dbg" << endl;
  }
  else {
    *log << "Threshold: note" << endl;
  }
}

logger::loglevel logger::threshold() {
  return _threshold;
}
