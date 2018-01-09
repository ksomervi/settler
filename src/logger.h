#ifndef SETTLER_LOGGER_H
#define SETTLER_LOGGER_H

#include <iostream>
using std::ostream;
//using std::cerr;
//using std::endl;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;


class logger {
public:
  enum loglevel {note, dbg, err};

private:
  loglevel _threshold;
  string fname;

  ostream * log;
  ofstream * logfile;

public:
  logger();
  logger(string);

  ~logger();
    
  void threshold(loglevel);
  loglevel threshold();

  void print(string);
  void debug(string);
  void error(string);

};
#endif //!define(SETTLER_LOGGER_H)


