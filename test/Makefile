EXE=test

all: build $(EXE)

$(EXE):
	g++ -o bin/test main.cpp -lmatte

build:
	@mkdir -p bin

clean:
	rm -rf bin