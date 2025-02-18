all: processes.o processes.h taskmanager.c build

processes.o: processes.h build
	gcc -c processes.c -o build/processes.o

taskmanager.c: processes.o build
	gcc taskmanager.c build/processes.o -o build/taskmanager.out

build:
	mkdir build

clean:
	rm -rf ./build/