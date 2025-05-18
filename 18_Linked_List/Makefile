all: tasklist.out

tasklist.out: tasklist.c linked_list.o
	gcc tasklist.c linked_list.o -o tasklist.out

linked_list.o: linked_list.h linked_list.c
	gcc -c linked_list.c -o linked_list.o

clean:
	rm -f *.out *.o