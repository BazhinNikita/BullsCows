CFLAGS = -Wall -Werror -MP -MMD -c -lncurses 
LFLAGS = -g -o
CMP = gcc

all: main

main: build/main.o build/bulls.o
	mkdir -p bin
	$(CMP) build/main.o build/bulls.o $(LFLAGS) bin/main -lncurses

build/main.o: src/main.c
	mkdir -p build
	$(CMP) $(CFLAGS) src/main.c -o build/main.o

build/bulls.o: src/bulls.c
	mkdir -p build
	$(CMP) $(CFLAGS) src/bulls.c -o build/bulls.o 

ctest:	build/mtest.o build/btest.o build/bulls.o
	mkdir -p bin
	mkdir -p bin/test
	$(CMP) build/mtest.o build/btest.o build/bulls.o $(LFLAGS) bin/test/test -lncurses

build/mtest.o: test/main.c
	mkdir -p build
	$(CMP) -I thirdparty $(CFLAGS) test/main.c -o build/mtest.o

build/btest.o: test/bulls.c
	mkdir -p build
	$(CMP) -I src -I thirdparty $(CFLAGS) test/bulls.c -o build/btest.o
	


clean:
	rm -rf bin build
