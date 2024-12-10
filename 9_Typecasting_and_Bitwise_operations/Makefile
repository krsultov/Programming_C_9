all: main

quadratic_roots: quadratic_roots.c quadratic_roots.h build
	gcc -c quadratic_roots.c -o build/quadratic_roots.o -libm -lm

main: main.c quadratic_roots build
	gcc main.c build/quadratic_roots.o -o build/main.out -lm

build:
	mkdir build

clean:
	rm -rf build/