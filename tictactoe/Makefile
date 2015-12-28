#Compiler to use
CC=g++

#The compiler flags
CFLAGS=-std=c++11 -c

all: tictactoe

tictactoe: main.o game.o player.o
	$(CC) main.o game.o player.o -o tictactoe
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp
	
player.o: player.cpp
	$(CC) $(CFLAGS) player.cpp

clean:
	rm *o tictactoe


