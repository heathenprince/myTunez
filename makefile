GCC = gcc

all: run clean
	make comp
	make run
	make clean

comp: main.c list.c list.h tunage.c tunage.h
	$(GCC) main.c list.c tunage.c -o tunez

main.o: main.c list.h tunage.h
	$(GCC) main.c

list.o: list.c list.h
	$(GCC) list.c

tunage.o: tunage.c tunage.h
	$(GCC) tunage.c

run: comp
	./tunez

clean:
	rm *~
	rm *.o
	rm tunez
