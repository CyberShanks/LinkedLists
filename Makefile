ll: linkedlist.o driver.o
	gcc -o ll linkedlist.o driver.o

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

driver.o: driver.c
	gcc -c driver.c

save: save.c
	gcc -o save save.c

clean:
	rm -f *.o