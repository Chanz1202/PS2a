# Makefile for ps2a
# Flags to save on typing all this out
CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

# Make ps2b
all:	NBody

# Universe executable
NBody:	main.o Universe.o
	$(CC) main.o Universe.o -o NBody $(SFMLFLAGS)

# object files
main.o:	main.cpp Universe.hpp
	$(CC) -c main.cpp Universe.hpp $(CFLAGS)

Universe.o:	Universe.cpp Universe.hpp
	$(CC) -c Universe.cpp Universe.hpp $(CFLAGS)

# Cleanup
clean:
	rm *.o
	rm *.gch
	rm NBody
