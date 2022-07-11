IDIR =bin
CC=g++
LDLIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lm  -lpng
CFLAGS=-I$(IDIR) -g -Wextra

LDFLAGS= $(CFLAGS)

ODIR=bin
LIBS= $(LDLIBS) $(LDFLAGS)

_DEPS = window.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o window.o system.o cpu.o debug.o semaphore.o main_class.o thread.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

GDIR=game
_GAME = pacman.h
GAME = $(patsubst %,$(GDIR)/%,$(_GAME))

$(GDIR)/%.o: %.c $(GAME)
	$(CC) -std=c++14 -c -o $@ $< $(CFLAGS) -Wextra


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -std=c++14 -c -o $@ $< $(CFLAGS) -Wextra

main: $(OBJ)
	$(CC) -std=c++14 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 