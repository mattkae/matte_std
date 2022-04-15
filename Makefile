LIBDIR=lib
OUT = $(LIBDIR)/libmatte.a
CC = g++
ODIR = obj
SDIR = src
INC = -Iinc

all: build $(OUT)

SRC = $(wildcard src/*.cpp)
OBJS := $(SRC:$(SDIR)/%.cpp=$(ODIR)/%.o)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS)
	ar rvs $(OUT) $^

build:
	@mkdir -p include
	@mkdir -p include/matte
	cp -f src/*.h include/matte/
	@mkdir -p $(ODIR)
	@mkdir -p $(LIBDIR)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT) rm -f include/matte/*.h


# https://stackoverflow.com/questions/39892692/how-to-implement-make-install-in-a-makefile
# PREFIX is environment variable, but if it is not set, then set default value
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

install: $(OUT)
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 lib/libmatte.a $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/include/
	install -m 644 include/matte.h $(DESTDIR)$(PREFIX)/include/
	@mkdir -p $(DESTDIR)$(PREFIX)/include/matte
	install -m 644 include/matte/*.h $(DESTDIR)$(PREFIX)/include/matte