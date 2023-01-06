ll: misc.o driver.o linkedlist.o
	gcc -o ll misc.o linkedlist.o driver.o

misc.o: misc.c
	gcc -c misc.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

driver.o: driver.c
	gcc -c driver.c

clean:
	rm -f *.o