finalapp: linkedlists.o save.o
	gcc -o finalapp linkedlists.o save.o

linkedlists.o: linkedlists.c
	gcc -c linkedlists.c

save.o: save.c
	gcc -c save.c

ll: linkedlists.c
	gcc -o ll linkedlists.c

save: save.c
	gcc -o save save.c

clean:
	rm -f *.o finalapp
