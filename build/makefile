IDIR = ../src
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
SDIR = ../src

_DEPS = parser.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o parser.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o main
