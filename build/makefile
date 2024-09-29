IDIR = ../src
CC = gcc
CFLAGS = -I$(IDIR) -g

ODIR = obj
SDIR = ../src

_DEPS = lexer.o
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o lexer.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o main
