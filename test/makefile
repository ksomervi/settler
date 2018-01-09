# Makefile for tests
#
CXX = g++

CXXFLAGS=-std=c++11 -Wall -g

INCLUDES = -I../src

COMPILE = ${CXX} ${CXXFLAGS} ${INCLUDES}

TARGETS = game_test random_test board_test

.PHONY: default all clean neat

default: all

all: ${TARGETS}

game_test: game_test.cpp board.cpp player.cpp

random_test: random_test.cpp
	${COMPILE} -o $@ $^

board_test: board_test.cpp $(addprefix ../src/,region.cpp board.cpp logger.cpp)
	${COMPILE} -o $@ $^


neat:
	-rm -f *.o *~

clean: neat
	-rm -f ${TARGETS}
