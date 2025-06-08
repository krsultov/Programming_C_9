all: library.out

library.out: library.c linked_list.o
	gcc library.c linked_list.o -o library.out

linked_list.o: linked_list.h linked_list.c
	gcc -c linked_list.c -o linked_list.o

clean:
	rm -f *.out *.o