CC=g++
CFLAGS=-c -Wall -Wextra -ansi -pedantic -std=c++11
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR := ./src
SOURCES=$(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=snake
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(wildcard $(SRC_DIR)/*.o) $(wildcard $(SRC_DIR)/*/*.o) $(EXECUTABLE)

install:
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)
