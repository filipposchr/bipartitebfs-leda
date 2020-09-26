name = program
src = $(wildcard src/*.cpp)
obj = $(src:.c=.o)

Leda = '/usr/local/LEDA/incl'
LedaLibs = '/usr/local/LEDA'

CC = g++

CFLAGS = -std=c++0x -O3
LIBFLAGS = -lleda -lm

DFLAGS =

all: $(name)

$(name): $(obj)
	$(CC) $(CFLAGS) -o  $@ $^ -I$(Leda) -L$(LedaLibs) $(LIBFLAGS) $(DFLAGS)

run:
	./$(name)

clean:
	rm -f $(name)
