GCC = gcc -g


songtest: list.c
	gcc list.c -o songtest

run: songtest
	./songtest

clean:
	rm -rf songtest
	rm -rf *~

debug: 
	gcc main.c -g -o songtest