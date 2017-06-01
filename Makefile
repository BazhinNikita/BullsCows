CFLAGS = -Wall -Werror -MP -MMD -lncurses
SOURCES = src/main.c src/bulls.c
OBJECTS = $(SOURCES:.c=.o)
.PH: clean all bullscows
 
Program :
	make bin/bullscows
bin/bullscows : build/main.o build/bulls.o
	mkdir -p bin;
	gcc build/main.o build/bulls.o -o bin/bullscows $(CFLAGS)
 
build/main.o : src/main.c src/bulls.h
	mkdir -p build;
	gcc -c src/main.c -o build/main.o $(CFLAGS)
 
build/bulls.o : src/bulls.c src/bulls.h
	mkdir -p build;
	gcc -c src/bulls.c -o build/bulls.o $(CFLAGS)
 	
clean :
	rm -rf build/*.d 
	rm -rf build/*.o
	rm bin/bullscows
	@echo "All files have been cleaned."
 	
-include build/*.d

