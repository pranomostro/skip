#change your build of skip

PREFIX=/usr/local

CC=gcc

CFLAGS=-Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS=-s

TARGET=skip
OBJS=skip.o
