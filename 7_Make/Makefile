all: build mystrings.o help.out strlength.out strconcat.out strcompare.out

help.out: build
	gcc help.c -o build/help.out
	./build/help.out

build:
	mkdir -p build

mystrings.o: mystrings.c mystrings.h build
	gcc -c mystrings.c -o build/mystrings.o

strlength.out: mystrings.o mystrings.h build
	gcc strlength.c -o build/strlength.out build/mystrings.o

strconcat.out: mystrings.c mystrings.h build
	gcc strconcat.c -o build/strconcat.out build/mystrings.o

strcompare.out: mystrings.c mystrings.h build
	gcc strcompare.c -o build/strcompare.out build/mystrings.o

clean:
	rm -rf ./build