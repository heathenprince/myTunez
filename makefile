GCC = gcc -g


songtest: list.c playlist.c main.c
	gcc list.c playlist.c main.c -o songtest

run: songtest
	./songtest

clean:
	rm -rf songtest
	rm -rf *~

debug: 
	gcc main.c -g -o songtest