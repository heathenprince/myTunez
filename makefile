GCC = gcc

comp: main.c list.c list.h tunage.c tunage.h
	$(GCC) main.c list.c tunage.c -o tunez

run: comp
	./tunez

clean:
	rm *~
	rm *.o
