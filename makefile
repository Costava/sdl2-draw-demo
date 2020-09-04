# makefile

run: build
	./Draw

build: Draw

Draw: main.c
	gcc -std=c99 -Wall --output $@ -lSDL2 main.c

clean:
	rm Draw
