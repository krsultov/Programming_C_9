all: bubblesort.out

bubblesort.out: bubblesort.c compare.o swap.o build
	gcc bubblesort.c ./build/compare.o ./build/swap.o -o ./build/bubblesort.out

compare.o: compare.c build
	gcc -c compare.c -o ./build/compare.o

swap.o: swap_ptr.c build
	gcc -c swap_ptr.c -o ./build/swap.o

build:
	mkdir ./build

clean:
	rm -rf ./build