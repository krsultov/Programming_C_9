all: safeadd safemultiply safesubtract safedivide

safeint.o: safeint.c safeint.h build
	gcc -c safeint.c -o build/safeint.o

safeadd: safeint.o safeadd.c safeint.h build
	gcc safeadd.c -o build/safeadd.out build/safeint.o

safemultiply: safeint.o safemultiply.c safeint.h build
	gcc safemultiply.c -o build/safemultiply.out build/safeint.o

safesubtract: safeint.o safesubtract.c safeint.h build
	gcc safesubtract.c -o build/safesubtract.out build/safeint.o

safedivide: safeint.o safedivide.c safeint.h build
	gcc safedivide.c -o build/safedivide.out build/safeint.o

clean:
	rm -rf build/

build:
	mkdir build