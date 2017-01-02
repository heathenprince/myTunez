GCC = gcc

all: run clean
	make comp
	make run
	make clean

comp: main.c list.c list.h tunage.c tunage.h
	$(GCC) list.c tunage.c -o tunez

run: comp
	./tunez

clean:
	rm *~
	rm *.o
