all: donors.out

donors.out: donors.c DynamicArray.o
	gcc donors.c DynamicArray.o -o donors.out

DynamicArray.o: DynamicArray.h DynamicArray.c
	gcc -c DynamicArray.c -o DynamicArray.o

clean:
	rm -f *.out *.o