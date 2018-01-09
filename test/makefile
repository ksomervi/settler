# Makefile for tests
#
CXX = g++

CXXFLAGS=-std=c++11 -Wall -g

INCLUDES = -I../src

COMPILE = ${CXX} ${CXXFLAGS} ${INCLUDES}

TARGETS = game_test random_test board_test

GT_SRCS = board.cpp player.cpp logger.cpp game.cpp region.cpp

VPATH = ../src

.PHONY: default all clean neat

default: all

all: ${TARGETS}

game_test: game_test.cpp ${GT_SRCS}
	${COMPILE} -o $@ $^

random_test: random_test.cpp
	${COMPILE} -o $@ $^

board_test: board_test.cpp $(addprefix ../src/,region.cpp board.cpp logger.cpp)
	${COMPILE} -o $@ $^


neat:
	-rm -f *.o *~ *.exe.stackdump

clean: neat
	-rm -f ${TARGETS}
