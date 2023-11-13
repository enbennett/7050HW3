##############################################################################
# Makefile for graph library
# CMP_SC 4050
# Fall 2023
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
CPPFLAGS = -Wall -Werror -c -g -I.
LINK = g++
LDFLAGS = -lm -lcs4050 -L.

default: testcc test

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

%.o : %.cc
	@echo Compiling $^ 
	@$(CPP) $(CPPFLAGS) $^

test : main.o Bellman-Ford.o UtilC.o libcs4050.a
	@echo Linking $@ 
	@$(LINK) $^ $(LDFLAGS) -o $@

testcc : maincc.o Bellman-Ford.o UtilCC.o libcs4050.a
	@echo Linking $@
	@$(LINK) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf test
	@rm -rf testcc
	@echo All Clean!
