all: processes.c processes.h taskmanager.c build

processes.c: processes.h build
	gcc -c processes.c -o build/processes.o

taskmanager.c: processes.c build
	gcc taskmanager.c build/processes.o -o build/taskmanager.out

build:
	mkdir build

clean:
	rm -rf ./build/