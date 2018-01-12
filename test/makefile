# Makefile for tests
#
CXX = g++

CXXFLAGS=-std=c++11 -Wall -g

INCLUDE = -I../src

COMPILE = ${CXX} ${CXXFLAGS} ${INCLUDE}

TARGETS = game_test random_test board_test town_test player_test

GT_SRCS = game_test.cpp board.cpp player.cpp logger.cpp game.cpp region.cpp
GT_SRCS += resource.cpp
GT_OBJS = $(subst .cpp,.o,${GT_SRCS})

TT_SRCS = town_test.cpp player.cpp town.cpp logger.cpp
TT_SRCS += resource.cpp
TT_OBJS = $(subst .cpp,.o,${TT_SRCS})

PT_SRCS = player_test.cpp logger.cpp player.cpp resource.cpp
PT_OBJS = $(subst .cpp,.o,${PT_SRCS})

BT_SRCS = board_test.cpp logger.cpp board.cpp region.cpp
BT_OBJS = $(subst .cpp,.o,${PT_SRCS})

VPATH = ../src

.cpp.o:
	${COMPILE} -c $?

.PHONY: default all clean neat

default: game_test

all: ${TARGETS}

town_test: ${TT_OBJS}
	${COMPILE} -o $@ $^

player_test: ${PT_OBJS}
	${CXX} -o $@ $^

game_test: ${GT_OBJS}
	${COMPILE} -o $@ $^

random_test: random_test.cpp
	${COMPILE} -o $@ $^

board_test: ${BT_OBJS}
	${COMPILE} -o $@ $^


neat:
	-rm -f *.o *~ *.exe.stackdump

clean: neat
	-rm -f ${TARGETS}
