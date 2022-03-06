OUT = lib/matte_std.a
CC = g++
ODIR = obj
SDIR = src
INC = -Iinc

_OBJS = mathlib.o logger.o matte_string.o matte_stringbuilder.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS)
	ar rvs $(OUT) $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)
